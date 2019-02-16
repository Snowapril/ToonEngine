#include "stdafx.h"
#include "FileSystem.h"
#include "Logger.h"

namespace Toon
{
	template <> FileSystem* Singleton< FileSystem >::instance = nullptr;

	FileSystem::FileSystem( std::string const & rootPath )
		: rootPath(rootPath)
	{
	}

	FileSystem::~FileSystem()
	{
		Logger::getConstInstance().infoMessage( "[Singleton] FileSystem instnace is released" );
	}

	void FileSystem::addDirectory( const std::string& label, const std::string& directory )
	{
		dirTable[label] = directory;
	}

	std::string FileSystem::getRootPath(void) const
	{
		return rootPath;
	}

	std::string FileSystem::getRelativePath( const std::string& label, const std::string& filename ) const
	{
		std::string retPath;

		if ( dirTable.find(label) != dirTable.end() )
			retPath = dirTable.at(label) + filename;

		return retPath;
	}

	FileSystem const & FileSystem::getConstInstance(void)
	{
		return *instance;
	}

	FileSystem & FileSystem::getMutableInstance(void)
	{
		return *instance;
	}
};