if(UNIX)
    set(LIBS dl)
endif()

add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(myapp MACOSX_BUNDLE main.cpp PluginLoader.cpp)
target_link_libraries(myapp core Boost::filesystem Boost::dynamic_linking Boost::disable_autolinking ${LIBS})

# set runtime paths of libraries to relative path
set_target_properties(myapp PROPERTIES BUILD_RPATH_USE_ORIGIN TRUE)
