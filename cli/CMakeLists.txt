###########################################################
#  logcraft_cli – command-line interface
###########################################################
cmake_minimum_required(VERSION 3.28)

project(LogCraftCli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###########################################################
#  Dependencies
###########################################################
# When building from root via add_subdirectory, logcraft_core target is already defined
# When building standalone, find logcraft_core via Conan
if(NOT TARGET logcraft::core)
    find_package(logcraft_core REQUIRED CONFIG)
endif()

###########################################################
#  CLI executable
###########################################################
file(GLOB_RECURSE CLI_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(logcraft_cli ${CLI_SOURCES})
target_include_directories(logcraft_cli PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(logcraft_cli PRIVATE logcraft::core)

###########################################################
#  Compile-time spdlog level elision (parity with core/server)
###########################################################
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(logcraft_cli PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)
else()
    target_compile_definitions(logcraft_cli PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO)
endif()
