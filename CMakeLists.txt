cmake_minimum_required(VERSION 3.31)
project(scribe VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# remove comment later
# add_library(${PROJECT_NAME} STATIC scribe.cpp)
add_executable(${PROJECT_NAME} main.cpp Scribe.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
