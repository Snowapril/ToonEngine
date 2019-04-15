#ifndef TOON_LOGGER_H
#define TOON_LOGGER_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"

#pragma warning(push)
#pragma warning( disable :  4244 )
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#pragma warning (pop)

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
		
		void infoMessage	( char const* msg ) const noexcept;
		void warnMessage	( char const* msg ) const noexcept;
		void errorMessage	( char const* msg ) const noexcept;

		template < typename... Args >
		void infoMessage (char const*, Args&&... ) const noexcept;
		template < typename... Args >
		void warnMessage (char const*, Args&&... ) const noexcept;
		template < typename... Args >
		void errorMessage(char const*, Args&&... ) const noexcept;
	};

	/****************************************************************************
						Logger class definition
	****************************************************************************/
	template < typename... Args >
	void Logger::infoMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->info( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::warnMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->warn( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::errorMessage(char const* fmt, Args&&... args ) const noexcept
	{
		logger->error( fmt, std::forward<Args>(args)... );
	}
};

#include "ToonHeaderPostfix.h"

#endif