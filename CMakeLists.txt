cmake_minimum_required(VERSION 3.13)

project(pulsar-client-cpp-example)
set(CMAKE_CXX_STANDARD 11)

find_path(PULSAR_INCLUDE_DIR pulsar/Client.h)
find_library(PULSAR_LIBRARIES pulsar)
message(STATUS "PULSAR_INCLUDE_DIR: ${PULSAR_INCLUDE_DIR}")
message(STATUS "PULSAR_LIBRARIES: ${PULSAR_LIBRARIES}")

include_directories(${PULSAR_INCLUDE_DIR})

add_executable(client-example main.cpp)
target_link_libraries(client-example PRIVATE ${PULSAR_LIBRARIES})