#pragma once

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <string>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::client;

class WeatherAPI {
public:
    std::string apiKey;
    std::string city;
    std::string units;

    WeatherAPI(std::string, std::string, std::string);

    
    http_client httpClient() const;
    void SendRequest();
};
