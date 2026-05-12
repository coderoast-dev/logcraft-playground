###########################################################
#  logcraft_playground - public scenarios + CLI consumer
###########################################################
cmake_minimum_required(VERSION 3.28)

project(LogCraftPlayground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LOGCRAFT_PLAYGROUND_BUILD_CLI "Build the LogCraft playground CLI" ON)

if(LOGCRAFT_PLAYGROUND_BUILD_CLI)
    add_subdirectory(cli)
    install(TARGETS logcraft_cli RUNTIME DESTINATION bin)
endif()

install(DIRECTORY scenario DESTINATION share/logcraft-playground)
install(FILES scenario_reference.md README.md DESTINATION share/logcraft-playground)
