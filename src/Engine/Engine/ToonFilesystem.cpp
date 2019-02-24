#include "stdafx.h"
#include "ToonFilesystem.h"
#include "ToonLogger.h"

namespace Toon
{
	template <> ToonFilesystem* ToonSingleton< ToonFilesystem >::instance = nullptr;

	ToonFilesystem::ToonFilesystem( std::string const & rootPath )
		: rootPath(rootPath)
	{
	}

	ToonFilesystem::~ToonFilesystem()
	{
		ToonLogger::getConstInstance().infoMessage( "[Singleton] FileSystem instnace is released" );
	}

	void ToonFilesystem::addDirectory( const std::string& label, const std::string& directory )
	{
		dirTable[label] = directory;
	}

	std::string ToonFilesystem::getRootPath(void) const
	{
		return rootPath;
	}

	std::string ToonFilesystem::getRelativePath( const std::string& label, const std::string& filename ) const
	{
		std::string retPath;

		if ( dirTable.find(label) != dirTable.end() )
			retPath = dirTable.at(label) + filename;

		return retPath;
	}

	ToonFilesystem const & ToonFilesystem::getConstInstance(void)
	{
		return *instance;
	}

	ToonFilesystem & ToonFilesystem::getMutableInstance(void)
	{
		return *instance;
	}
};