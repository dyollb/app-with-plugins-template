#pragma once

#include <string>
#include <vector>

#if defined(WIN32)
#	ifdef core_EXPORTS
#		define CORE_API __declspec(dllexport)
#	else
#		define CORE_API __declspec(dllimport)
#	endif
#else
#	define CORE_API __attribute__((visibility("default")))
#endif

class CORE_API Plugin
{
public:
	Plugin();
	virtual ~Plugin() = default;

	virtual std::string SomeValue() const = 0;
};

class CORE_API PluginRegistry
{
public:
	static std::vector<Plugin*> RegisteredPlugins();
};
