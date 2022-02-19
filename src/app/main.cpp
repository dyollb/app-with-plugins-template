#include "PluginLoader.h"

#include "../core/Plugin.h"

#include <filesystem>
#include <iostream>

int main(int argc, char** argv)
{
    auto current_dir = std::filesystem::absolute(std::filesystem::path(argv[0])).parent_path();
    LoadPlugins(current_dir);

#ifdef __APPLE__
    // plugins are installed into Frameworks directory
    auto plugin_dir = current_dir.parent_path() / "Frameworks";
    if (!std::filesystem::exists(plugin_dir))
    {
        // we are in build directory
        plugin_dir = current_dir / "../../../";
    }
    LoadPlugins(plugin_dir);
#endif

    auto plugins = PluginRegistry::RegisteredPlugins();
    for (const auto& p: plugins)
    {
        std::cerr << "Plugin: " << p->SomeValue() << std::endl;
    }
    
    return plugins.empty() ? EXIT_FAILURE : EXIT_SUCCESS;
}