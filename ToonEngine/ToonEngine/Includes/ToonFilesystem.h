#ifndef TOON_FILESYSTEM_H
#define TOON_FILESYSTEM_H

#include "ToonHeaderPrefix.h"

#include <ToonSingleton.h>
#include <string>
#include <unordered_map>
#include <filesystem>

namespace Toon
{
	/****************************************************************************
						Filesystem class declaration
	****************************************************************************/
	class Filesystem : public Common::Singleton<Filesystem>
	{
	private:
		std::unordered_map< std::string, std::string > dirTable;
		std::string rootPath;
	public:
		Filesystem( std::string const & rootPath );
		~Filesystem();

		void		setDirectory	( std::string const & label, std::string const & directory );
		std::string getRootPath		( void ) const;
		std::string getAbsolutePath	( std::string const & filename ) const;
	public:
		bool isExists(std::string const& relativePath, std::filesystem::file_status s = std::filesystem::file_status{}) const;
		void createDirectory(std::string const & relativePath) const;
	};
};

#include "ToonHeaderPostfix.h"

#endif //FILE_SYSTEM_H