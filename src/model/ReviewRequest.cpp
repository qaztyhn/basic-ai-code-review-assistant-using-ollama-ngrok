#include "model/ReviewRequest.h"
#include "infra/JsonUtils.h"


std::string ReviewRequest::toJson() {
    std::string fullPrompt = promptRaw + "\n\nCode:\n" + sourceCode;
    
    return "{"
           "\"model\": \"" + modelName + "\","
           "\"prompt\": \"" + JsonUtils::escape(fullPrompt) + "\","
           "\"stream\": false"
           "}";
}