#include "PluginA.h"

#include <iostream>

namespace {
PluginA register_addon;
}

std::string PluginA::SomeValue() const
{
    return "A";
}
