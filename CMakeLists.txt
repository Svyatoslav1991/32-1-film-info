# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("32-1-film-info")

set(CMAKE_CXX_STANDARD 14)

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann_json/include)

add_executable (32-1-film-info "main.cpp")

target_link_libraries(32-1-film-info PRIVATE nlohmann_json)

