#ifndef LOGGER_H
#define LOGGER_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <string>
#include <memory>

namespace Toon
{
	/****************************************************************************
						Logger class declaration
	****************************************************************************/
	class Logger : public Singleton<Logger>
	{
	private:
		std::shared_ptr<spdlog::async_logger> logger;
	public:
		Logger(std::string const& logDirectory);
		~Logger();
		
		void infoMessage	( char const* msg ) const;
		void warnMessage	( char const* msg ) const;
		void errorMessage	( char const* msg ) const;

		template < typename... Args >
		void infoMessage(char const* fmt, Args&&... args ) const;
		template < typename... Args >
		void warnMessage(char const*, Args&&... args ) const;
		template < typename... Args >
		void errorMessage(char const*, Args&&... args ) const;
	};

	/****************************************************************************
						Logger class definition
	****************************************************************************/
	template < typename... Args >
	void Logger::infoMessage(char const* fmt, Args&&... args ) const
	{
		logger->info( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::warnMessage(char const* fmt, Args&&... args ) const
	{
		logger->warn( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::errorMessage(char const* fmt, Args&&... args ) const
	{
		logger->error( fmt, std::forward<Args>(args)... );
	}
};

#include "ToonHeaderPostfix.h"

#endif