#include "RegifterCtrl.h"

void RegifterCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    drogon::MultiPartParser fileParser;
    Json::Value retJson;

    if (fileParser.parse(req) < 0)
    {
        LOG_ERROR << "get file from client failed";
        retJson["success"] = "false";
        auto resp = HttpResponse::newHttpJsonResponse(retJson);
        callback(resp);
        return;
    }

    auto fileList = fileParser.getFiles();

    auto & file = fileList.front();
    auto re = HttpResponse::newHttpResponse();

    re->setBody(file.fileContent());
    re->setStatusCode(k200OK);
    re->setContentTypeCode(req->getContentType());
    re->addHeader("Content-Disposition", "attachment; filename=" + file.getFileName());

    callback(re);
}
