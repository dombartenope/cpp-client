cmake_minimum_required(VERSION 3.22)
project(CppRestOneSignalAPIClientTest)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")



# OneSignal Client Library
add_subdirectory(deps/onesignal)

# Executables for tests
add_executable(tests test.cpp)

target_link_libraries(tests CppRestOneSignalAPIClient)