#include "../core/Plugin.h"

class PluginA : public Plugin
{
public:
	PluginA() = default;
	~PluginA() override = default;

	std::string SomeValue() const override;
};
