#ifndef LOGGER_H
#define LOGGER_H

#include "ToonHeaderPrefix.h"
#include "Singleton.h"
#include <spdlog/spdlog.h>
#include <string>
#include <memory>

namespace Toon
{
	class Logger : public Singleton<Logger>
	{
	private:
		std::unique_ptr<spdlog::logger> console;
	public:
		Logger();
		~Logger();
		
		void infoMessage	( std::string const & msg ) const;
		void warnMessage	( std::string const & msg ) const;
		void errorMessage	( std::string const & msg ) const;

		template < typename... Args >
		void infoMessage( char const * fmt, Args&&... args ) const;
		template < typename... Args >
		void warnMessage( char const * fmt, Args&&... args ) const;
		template < typename... Args >
		void errorMessage( char const * fmt, Args&&... args ) const;
	public:
		static Logger const&	getConstInstance	(void);
		static Logger &			getMutableInstance	(void);
		static bool				isDestroyed			(void) { return instance == nullptr; }
	};

	template < typename... Args >
	void Logger::infoMessage( char const * fmt, Args&&... args ) const
	{
		console->info( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::warnMessage( char const * fmt, Args&&... args ) const
	{
		console->warn( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void Logger::errorMessage( char const * fmt, Args&&... args ) const
	{
		console->error( fmt, std::forward<Args>(args)... );
	}
};

#include "ToonHeaderPostfix.h"

#endif