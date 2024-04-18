#include <iostream>
#include "WeatherAPI.h"
#include <string>

int main(int argc, char* argv[]) {

    // Initialize our variables
    std::string apiKey = argv[0];
    std::string city = argv[1];
    std::string units = argv[2];
    
    // Construct WeatherAPI object

    //WeatherAPI weather(apiKey, city, units);
    WeatherAPI weather = WeatherAPI(apiKey=apiKey, city=city, units=units);
    // Call the SendRequest method to retrieve weather data
    weather.SendRequest();

    return 0;
}
