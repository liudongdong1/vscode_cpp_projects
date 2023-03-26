cmake_minimum_required(VERSION 3.21)

project(vscode_vcpkg_template 
        VERSION 1.0.0
        LANGUAGES CXX)

set(CXX_STANDARD            17)
set(CXX_STANDARD_REQUIRED   ON)
set(CXX_EXTENSIONS          OFF)

add_executable(vscode_vcpkg_template main.cpp)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(vscode_vcpkg_template 
    PRIVATE spdlog::spdlog spdlog::spdlog_header_only)