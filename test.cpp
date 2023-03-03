#include <iostream>
#include <cstdio>
#include "CppRestOneSignalAPIClient/ApiClient.h"
#include "CppRestOneSignalAPIClient/ApiConfiguration.h"
#include "CppRestOneSignalAPIClient/api/DefaultApi.h"

using namespace std;

using com::onesignal::client::api::ApiClient;
using com::onesignal::client::api::ApiConfiguration;
using com::onesignal::client::api::DefaultApi;
using com::onesignal::client::api::Notification;
using com::onesignal::client::api::StringMap;

using utility::string_t;
using utility::conversions::to_string_t;

const std::string APP_ID = "c78671ca-6d42-4d5b-98c1-f0775e95d0f4";
const std::string APP_KEY_TOKEN = "ZDc2MTg1MWItMjFhMC00NTdhLThiNzctZTcxZTdjNjkyNDNl";
const std::string USER_KEY_TOKEN = "<YOUR_USER_KEY_TOKEN>";

static DefaultApi * createApi() {
    // Settings up the client
    const auto configuration = ApiClient::getDefaultConfiguration();
    configuration->setAppKeyToken(APP_KEY_TOKEN);
    configuration->setUserKeyToken(USER_KEY_TOKEN);

    const auto apiClient = std::make_shared<ApiClient>(configuration);

    return new DefaultApi(apiClient);
}

static std::shared_ptr<Notification> createNotification() {
    const auto notification = std::make_shared<Notification>();
    notification->setAppId(APP_ID);

    const auto content = std::make_shared<StringMap>();
    content->setEn(to_string_t("OneSignal C++ Client Test: Create notification"));
    std::vector<string_t> vect{ to_string_t("Subscribed Users") };

    notification->setContents(content);
    notification->setIncludedSegments(vect);
    // notification->setIsAnyWeb(true);
    // notification->setIsChrome(true);


    return notification;
}

int main(int argc, char **argv){

    const auto api = createApi();

    // Creating a notification
    const auto notification = createNotification();

    // Send a notification
    const auto response = api->createNotification(notification);
    const auto & responseData = response.get();

    std::cout << "test" << endl;;
    std::cout << (responseData->getId());

    return 0;
}