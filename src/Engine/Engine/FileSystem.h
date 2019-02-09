#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "Singleton.h"
#include <string>
#include <unordered_map>

class FileSystem : public Singleton<FileSystem>
{
private:
	std::unordered_map<std::string, std::string> dirTable;
	std::string rootPath;
public:
	FileSystem() = default;

	void		addDirectory   ( const std::string& label, const std::string& directory );
	std::string getRootPath	   ( void ) const;
	std::string getRelativePath( const std::string& label, const std::string& filename ) const;
};

#endif //FILE_SYSTEM_H