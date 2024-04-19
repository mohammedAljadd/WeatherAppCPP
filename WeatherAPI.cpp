#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <string>
#include <iostream>
#include "WeatherAPI.h"
using namespace web;
using namespace web::http;
using namespace web::http::client;



WeatherAPI::WeatherAPI(std::string apiKey_, std::string city_, std::string units_)
	{
		apiKey = apiKey_;
		city = city_;
		units = units_;
	}

		
	// Create HTTP client to send requests
	http_client WeatherAPI::httpClient() const {
		uri_builder builder(U("https://api.openweathermap.org/data/2.5/weather"));
		builder.append_query(U("q"), utility::conversions::to_string_t(city));
        builder.append_query(U("appid"), utility::conversions::to_string_t(apiKey));
		builder.append_query(U("units"), utility::conversions::to_string_t(units));
		http_client client(builder.to_string());
		return client;
	}

	// Send request
    void WeatherAPI::SendRequest() {
        // Capture units by reference in the lambda function
        auto& unitsRef = units;

        // HTTP client
        http_client client = httpClient();

        // Send a GET request asynchronously
        client.request(methods::GET).then([&unitsRef](http_response response) {
            // Check if the request was successful
            if (response.status_code() == status_codes::OK) {
                // Extract and parse the JSON response
                return response.extract_json();
            }
            else {
                // Print an error message
                std::cerr << "Failed to get response. Status code: " << response.status_code() << std::endl;
                return pplx::task_from_result(json::value());
            }
        }).then([&unitsRef](json::value responseBody) {
            // Check if the "main" object and "weather" array exist in the response
            if (responseBody.has_field(U("main")) && responseBody.has_field(U("weather"))) {
                // Get temperature and humidity from the "main" object
                auto& mainObject = responseBody[U("main")];
                if (mainObject.has_field(U("temp"))) {
                    double temperature = mainObject[U("temp")].as_double();
                    if (unitsRef == "metric") {
                        std::cout << "Temperature: " << temperature << " Celsius" << std::endl;
                    }
                    else {
                        std::cout << "Temperature: " << temperature << " Fahrenheit" << std::endl;
                    }
                }
                if (mainObject.has_field(U("humidity"))) {
                    int humidity = mainObject[U("humidity")].as_integer();
                    std::cout << "Humidity: " << humidity << "%" << std::endl;
                }

                // Get description (sky condition) from the first element of the "weather" array
                auto& weatherArray = responseBody[U("weather")].as_array();
                if (weatherArray.size() > 0) {
                    auto& weatherObject = weatherArray[0];
                    if (weatherObject.has_field(U("description"))) {
                        utility::string_t description = weatherObject[U("description")].as_string();
                        std::cout << "Sky condition: " << utility::conversions::to_utf8string(description) << std::endl;
                    }
                }
            }
        }).wait();


	}




