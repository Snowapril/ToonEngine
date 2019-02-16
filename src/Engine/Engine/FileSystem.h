#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "ToonHeaderPrefix.h"
#include "Singleton.h"
#include <string>
#include <unordered_map>

namespace Toon
{
	class FileSystem : public Singleton<FileSystem>
	{
	private:
		std::unordered_map< std::string, std::string > dirTable;
		std::string rootPath;
	public:
		FileSystem( std::string const & rootPath );
		~FileSystem();

		void		addDirectory	( const std::string& label, const std::string& directory );
		std::string getRootPath		( void ) const;
		std::string getRelativePath	( const std::string& label, const std::string& filename ) const;
	public:
		static FileSystem const&	getConstInstance(void);
		static FileSystem &			getMutableInstance(void);
		static bool					isDestroyed(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif //FILE_SYSTEM_H