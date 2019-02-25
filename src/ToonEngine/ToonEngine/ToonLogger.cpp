#include "stdafx.h"
#include "ToonLogger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Toon
{
	template <> ToonLogger* ToonSingleton<ToonLogger>::instance = nullptr;

	ToonLogger::ToonLogger()
	{
		auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		console = std::make_unique<spdlog::logger>("setup", sink);
		
		console->set_level(spdlog::level::err);
	}

	ToonLogger::~ToonLogger()
	{
		ToonLogger::getConstInstance().infoMessage("[Singleton] Logger instnace is released");
		console.reset();
	}

	void ToonLogger::infoMessage(std::string const & msg) const
	{
		console->info(msg);
	}

	void ToonLogger::warnMessage(std::string const & msg) const
	{
		console->warn(msg);
	}

	void ToonLogger::errorMessage(std::string const & msg) const
	{
		console->error(msg);
	}

	ToonLogger const & ToonLogger::getConstInstance(void)
	{
		return *instance;
	}

	ToonLogger & ToonLogger::getMutableInstance(void)
	{
		return *instance;
	}

};