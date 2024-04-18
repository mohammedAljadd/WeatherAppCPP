cmake_minimum_required(VERSION 3.10)
project(WeatherAppCPP)

# Set paths
set(CPPREST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cpprest/include")
set(CPPREST_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cpprest/lib")

# Add your project's source files
set(SOURCES
    Main.cpp
    WeatherAPI.cpp
    WeatherAPI.h
)

# Include directories
include_directories(${CPPREST_INCLUDE_DIR})

# Create executable
add_executable(WeatherAppCPP ${SOURCES})

# Link against cpprest library
target_link_directories(WeatherAppCPP PRIVATE ${CPPREST_LIB_DIR})
target_link_libraries(WeatherAppCPP PRIVATE cpprest)

# Copy DLL file to the output directory
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cpprest/lib/cpprest142_2_10d.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
