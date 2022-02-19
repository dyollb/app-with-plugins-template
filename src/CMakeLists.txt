cmake_minimum_required(VERSION 3.12)
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


find_package(Boost 1.74 REQUIRED COMPONENTS filesystem)


set(PLUGIN_NAMES "")
add_subdirectory(core)
add_subdirectory(plugin)
add_subdirectory(app)
add_subdirectory(tests)

install(TARGETS myapp ${PLUGIN_NAMES}
    BUNDLE  DESTINATION bundle COMPONENT Runtime
    LIBRARY DESTINATION bundle/myapp.app/Contents/Frameworks COMPONENT Runtime
)

set(BUNDLE_PLUGINS "")
foreach(plugin ${PLUGIN_NAMES})
    list(APPEND BUNDLE_PLUGINS 
        ${CMAKE_INSTALL_PREFIX}/bundle/myapp.app/Contents/Frameworks/${CMAKE_SHARED_LIBRARY_PREFIX}${plugin}${CMAKE_SHARED_LIBRARY_SUFFIX}
    )
endforeach()

set(BUNDLE_LIB_DIRS
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    ${Boost_LIBRARY_DIRS}
)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Bundle.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/Bundle.cmake
    @ONLY
)

install(SCRIPT ${CMAKE_CURRENT_BINARY_DIR}/Bundle.cmake)