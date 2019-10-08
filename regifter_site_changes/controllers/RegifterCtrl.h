#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class RegifterCtrl:public drogon::HttpSimpleController<RegifterCtrl>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    //list path definitions here;

    PATH_ADD("/upload", Post);

    PATH_LIST_END
};
