#include "infra/CurlClient.h"
#include <iostream>
#include <stdexcept>

CurlClient::CurlClient() {
    curl_global_init(CURL_GLOBAL_ALL);
}
CurlClient::~CurlClient() {
    curl_global_cleanup();
}

size_t CurlClient::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* str = (std::string*)userp;
    str->append((char*)contents, totalSize);
    return totalSize;
}

std::string CurlClient::post(const std::string& url, const std::string& jsonPayload) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        
        headers = curl_slist_append(headers, "ngrok-skip-browser-warning: true");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 300L); 

        CURLcode res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            std::string errorMsg = curl_easy_strerror(res);
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            
            throw std::runtime_error("Network Error (Curl): " + errorMsg);
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    } else {
        throw std::runtime_error("Failed to initialize cURL");
    }
    return readBuffer;
}