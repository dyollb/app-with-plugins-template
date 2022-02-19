add_library(plugin.ext PluginA.cpp)
target_link_libraries(plugin.ext core)

#set(PLUGIN_NAMES ${PLUGIN_NAMES} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_SHARED_LIBRARY_PREFIX}plugin.ext${CMAKE_SHARED_LIBRARY_SUFFIX} PARENT_SCOPE)
set(PLUGIN_NAMES ${PLUGIN_NAMES} plugin.ext PARENT_SCOPE)
