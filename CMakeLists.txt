# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(WeatherAppCPP VERSION 1.0.0)

# ---------------------- Linking CPPREST library ----------------------

# Include directories for cpprest
include_directories(Dependencies/cpprest/include)       # location of header files

# Add cpprest library
link_directories(Dependencies/cpprest/lib)              # location of the precompiled cpprest library
link_libraries(cpprest142_2_10d)                        # name of the library .lib file 

# --------------------------- Adding WeatherAPI library ----------------------------------

# Adding WeatherAPI library
add_library(
    WeatherAppCPPLib        # I called this WeatherAppCPPLib
    WeatherAPI.h            # header file
    WeatherAPI.cpp          # cpp file
)

# Creating the executable
add_executable(WeatherAppCPP Main.cpp)    # main exe

# Linking WeatherAppCPP with WeatherAppCPPLib
target_link_libraries(WeatherAppCPP PRIVATE WeatherAppCPPLib)

# Copy the cpprest DLL file to the target directory
# the cpprest dll file must be near exe file
add_custom_command(TARGET WeatherAppCPP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/Dependencies/cpprest/lib/cpprest142_2_10d.dll
    ${CMAKE_BINARY_DIR}/Debug)
