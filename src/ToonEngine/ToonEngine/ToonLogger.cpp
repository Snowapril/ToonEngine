#include "stdafx.h"
#include "ToonLogger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Toon
{
	template <> Logger* Singleton<Logger>::instance = nullptr;

	Logger::Logger()
	{
		auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		console = std::make_unique<spdlog::logger>("setup", sink);
		
		console->set_level(spdlog::level::err);
	}

	Logger::~Logger()
	{
		Logger::getConstInstance().infoMessage("[Singleton] Logger instnace is released ({0:x})", reinterpret_cast<void*>(instance));
		console.reset();
	}

	void Logger::infoMessage(std::string const & msg) const
	{
		console->info(msg);
	}

	void Logger::warnMessage(std::string const & msg) const
	{
		console->warn(msg);
	}

	void Logger::errorMessage(std::string const & msg) const
	{
		console->error(msg);
	}

	Logger const & Logger::getConstInstance(void)
	{
		return *instance;
	}

	Logger & Logger::getMutableInstance(void)
	{
		return *instance;
	}

};