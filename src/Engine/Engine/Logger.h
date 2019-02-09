#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <memory>
#include "Singleton.h"

class Logger : public Singleton<Logger> 
{
private:
	std::shared_ptr<spdlog::logger> console;
public:
	void initLogger(spdlog::level::level_enum logLevel);
	std::shared_ptr<spdlog::logger>	getConsole() const;
};

#ifdef _DEBUG
#define INIT_LOGGER() ( Logger::getMutableInstance().initLogger(spdlog::level::trace))
#else
#define INIT_LOGGER() ( Logger::getMutableInstance().initLogger(spdlog::level::warn))
#endif

#ifdef _DEBUG
#define INFO_LOG(format, ...)  (Logger::getConstInstance().getConsole()->info((format), __VA_ARGS__))
#else
#define INFO_LOG(format, ...) 
#endif

#define ERROR_LOG(format, ...) ( Logger::getConstInstance().getConsole()->error((format), __VA_ARGS__))


#endif