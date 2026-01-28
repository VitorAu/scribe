cmake_minimum_required(VERSION 4.1)
project(scribe)

set(CMAKE_CXX_STANDARD 23)

add_library(scribe STATIC scribe.cpp)
target_include_directories(scribe
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
