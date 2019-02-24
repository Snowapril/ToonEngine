#ifndef LOGGER_H
#define LOGGER_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <spdlog/spdlog.h>
#include <string>
#include <memory>

namespace Toon
{
	class ToonLogger : public ToonSingleton<ToonLogger>
	{
	private:
		std::unique_ptr<spdlog::logger> console;
	public:
		ToonLogger();
		~ToonLogger();
		
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
		static ToonLogger const&	getConstInstance	(void);
		static ToonLogger &			getMutableInstance	(void);
		static bool				isDestroyed			(void) { return instance == nullptr; }
	};

	template < typename... Args >
	void ToonLogger::infoMessage( char const * fmt, Args&&... args ) const
	{
		console->info( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void ToonLogger::warnMessage( char const * fmt, Args&&... args ) const
	{
		console->warn( fmt, std::forward<Args>(args)... );
	}

	template < typename... Args >
	void ToonLogger::errorMessage( char const * fmt, Args&&... args ) const
	{
		console->error( fmt, std::forward<Args>(args)... );
	}
};

#include "ToonHeaderPostfix.h"

#endif