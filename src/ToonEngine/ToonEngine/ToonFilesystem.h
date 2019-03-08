#ifndef TOON_FILESYSTEM_H
#define TOON_FILESYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <string>
#include <unordered_map>

namespace Toon
{
	/****************************************************************************
						Filesystem class declaration
	****************************************************************************/
	class Filesystem : public Singleton<Filesystem>
	{
	private:
		std::unordered_map< std::string, std::string > dirTable;
		std::string rootPath;
	public:
		Filesystem( std::string const & rootPath );
		~Filesystem();

		void		setDirectory	( const std::string& label, const std::string& directory );
		std::string getRootPath		( void ) const;
		std::string getRelativePath	( const std::string& label, const std::string& filename ) const;
	public:
		bool isExists(std::string const & relativePath) const;
		void createDirectory(std::string const & relativePath) const;
	};
};

#include "ToonHeaderPostfix.h"

#endif //FILE_SYSTEM_H