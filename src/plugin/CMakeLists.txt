add_library(plugin.ext PluginA.cpp)
target_link_libraries(plugin.ext core)

set(PLUGIN_NAMES ${PLUGIN_NAMES} plugin.ext PARENT_SCOPE)
