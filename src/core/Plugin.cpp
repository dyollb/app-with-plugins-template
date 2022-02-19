#include "Plugin.h"

namespace {
std::vector<Plugin*> addons;
}

Plugin::Plugin() { addons.push_back(this); }

std::vector<Plugin*> PluginRegistry::RegisteredPlugins() { return addons; }
