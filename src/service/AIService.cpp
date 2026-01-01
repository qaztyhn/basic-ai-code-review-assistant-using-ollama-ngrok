#include "service/AIService.h"
#include "infra/JsonUtils.h"
#include <iostream>

AIService::AIService(std::unique_ptr<IHttpClient> client, std::string url, std::string model)
    : httpClient(std::move(client)), serverUrl(url), modelName(model) {}

ReviewResponse AIService::reviewCode(ReviewRequest request) {
    ReviewResponse response;

    std::string apiUrl = this->serverUrl + "api/generate";
    std::string jsonResponse = this->httpClient->post(apiUrl, request.toJson());

    if (jsonResponse.empty()) {
        response.success = false;
        response.errorMessage = "Network Error or Empty Response";
    } else {
        response.success = true;
        response.rawJson = jsonResponse;
        response.content = JsonUtils::extractField(jsonResponse, "response");
    }
    return response;
}