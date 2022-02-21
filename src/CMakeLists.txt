cmake_minimum_required(VERSION 3.14)
project(TestProject CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BUILD_SHARED_LIBS ON)
include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


find_package(Boost 1.71 REQUIRED COMPONENTS filesystem)


set(PLUGIN_NAMES "")
add_subdirectory(core)
add_subdirectory(plugin)
add_subdirectory(app)
add_subdirectory(tests)


include(${CMAKE_CURRENT_SOURCE_DIR}/Install.cmake)
install_app(myapp PLUGIN_NAMES ${PLUGIN_NAMES} LIBRARY_DIRS ${Boost_LIBRARY_DIRS})
