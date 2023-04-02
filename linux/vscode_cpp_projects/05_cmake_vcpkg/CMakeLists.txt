# https://github.com/microsoft/vcpkg/issues/11354#issuecomment-633248199
# https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html

cmake_minimum_required(VERSION 3.12) 
set(CMAKE_TOOLCHAIN_FILE D:\\work_project\\c++\\vcpkg\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake)
project(CmakeVcpkg VERSION 0.1.0)

find_package(BZip2 REQUIRED)


add_executable(CmakeVcpkg bsdiff.c)
target_link_libraries(CmakeVcpkg PRIVATE BZip2::BZip2)

# DISPLAY ALL VARIABLES  S.O.9298278
# get_cmake_property(_variableNames VARIABLES)
# set(SEARCH_TERM fmt)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     unset(MATCHED)
#     string(REGEX MATCH ${SEARCH_TERM} MATCHED ${_variableName})
#     if (NOT MATCHED)
#         continue()
#     endif()
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()   