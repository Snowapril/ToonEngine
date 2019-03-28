#include "stdafx.h"
#include "ToonLogger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>
#include "ToonFilesystem.h"

namespace Toon
{
	/****************************************************************************
						Logger class definition
	****************************************************************************/
	template <> Logger* Singleton<Logger>::instance = nullptr;

	Logger::Logger(std::string const& logDirectory)
	{
		auto& fs = Filesystem::getConstInstance();
		if (!fs.isExists(logDirectory))
		{
			fs.createDirectory(logDirectory);
		}

		spdlog::init_thread_pool(8192, 2);
#ifdef _DEBUG
		auto stdoutSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logDirectory + std::string(OBFUSCATE("engine.log")), 1048576 * 3, 2); // TODO : will be replaced to filesystem related string 
		std::vector<spdlog::sink_ptr> sinks{ stdoutSink, fileSink };
#else
		auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logDirectory + std::string(OBFUSCATE("engine.log")), 1048576 * 3, 2); // TODO : will be replaced to filesystem related string 
		std::vector<spdlog::sink_ptr> sinks{ fileSink };
#endif
		logger = std::make_shared<spdlog::async_logger>(OBFUSCATE("toonLogger"), begin(sinks), end(sinks), spdlog::thread_pool(), spdlog::async_overflow_policy::overrun_oldest);
		logger->set_level(spdlog::level::trace);

		using namespace std::chrono_literals;
		spdlog::register_logger(logger);
	}

	Logger::~Logger()
	{
		Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("Logger instance is released"), reinterpret_cast<void*>(instance));
		spdlog::shutdown();
		logger.reset();
	}

	void Logger::infoMessage(std::string const & msg) const
	{
		logger->info(msg);
	}

	void Logger::warnMessage(std::string const & msg) const
	{
		logger->warn(msg);
	}

	void Logger::errorMessage(std::string const & msg) const
	{
		logger->error(msg);
	}

};