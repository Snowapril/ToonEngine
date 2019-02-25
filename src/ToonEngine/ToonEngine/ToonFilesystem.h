#ifndef TOON_FILESYSTEM_H
#define TOON_FILESYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <string>
#include <unordered_map>

namespace Toon
{
	class ToonFilesystem : public ToonSingleton<ToonFilesystem>
	{
	private:
		std::unordered_map< std::string, std::string > dirTable;
		std::string rootPath;
	public:
		ToonFilesystem( std::string const & rootPath );
		~ToonFilesystem();

		void		addDirectory	( const std::string& label, const std::string& directory );
		std::string getRootPath		( void ) const;
		std::string getRelativePath	( const std::string& label, const std::string& filename ) const;
	public:
		static ToonFilesystem const&	getConstInstance(void);
		static ToonFilesystem &			getMutableInstance(void);
		static bool					isDestroyed(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif //FILE_SYSTEM_H