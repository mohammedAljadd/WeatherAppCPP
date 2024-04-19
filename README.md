# WeatherAppCPP

WeatherAppCPP is a C++ application that retrieves weather information using the OpenWeatherMap API.

## Prerequisites

Before building and running WeatherAppCPP, ensure that you have the following prerequisites installed:

- CMake (minimum version 3.12)

## Building

To build WeatherAppCPP, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the root directory of the project.
3. Create a build directory:
    ```
    mkdir build
    cd build
    ```
4. Run CMake to generate build files:
    ```
    cmake ..
    ```
5. Build the project:
    ```
    cmake --build .
    ```

## Usage

Before running WeatherAppCPP, you need to sign up for an account on [OpenWeatherMap](https://openweathermap.org/) to obtain an API key. It's completely free for the our case.

You will generate an API key in this link [api keys](https://home.openweathermap.org/api_keys).

After obtaining your API key, follow these steps to run WeatherAppCPP:

1. Navigate to the build/debug directory:
    ```
    cd build/debug
    ```
2. Run the executable with the following arguments:
    - `<api_key>`: Your OpenWeatherMap API key
    - `<city>`: The name of the city for which you want to retrieve weather information
    - `<units>`: Units for temperature (metric or imperial)
    
    Example:
    ```
    ./WeatherAppCPP <api_key> <city> <units>
    ```
3. After running the executable, the output will display the temperature, humidity, and weather conditions for the specified city.


## cpprest library

In this project, I used the cpprest library my Microsoft to send requests to the API. All the necessary files are put in the Dependecies folder. The linking is made via cmake.