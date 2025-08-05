cmake_minimum_required(VERSION 3.20)
project(job-app-ms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include
include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(${PROJECT_NAME}
		src/main.cpp
		src/application.cpp
		src/cli.cpp
		src/manager.cpp
)

# Optional: Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
