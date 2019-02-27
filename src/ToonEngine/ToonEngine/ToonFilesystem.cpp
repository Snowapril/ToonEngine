#include "stdafx.h"
#include "ToonFilesystem.h"
#include "ToonLogger.h"

namespace Toon
{
	template <> Filesystem* Singleton< Filesystem >::instance = nullptr;

	Filesystem::Filesystem( std::string const & rootPath )
		: rootPath(rootPath)
	{
	}

	Filesystem::~Filesystem()
	{
		Logger::getConstInstance().infoMessage( "[Singleton] FileSystem instnace is released ({0:x})", reinterpret_cast<void*>(instance) );
	}

	void Filesystem::addDirectory( const std::string& label, const std::string& directory )
	{
		dirTable[label] = directory;
	}

	std::string Filesystem::getRootPath(void) const
	{
		return rootPath;
	}

	std::string Filesystem::getRelativePath( const std::string& label, const std::string& filename ) const
	{
		std::string retPath;

		if ( dirTable.find(label) != dirTable.end() )
			retPath = dirTable.at(label) + filename;

		return retPath;
	}

	Filesystem const & Filesystem::getConstInstance(void)
	{
		return *instance;
	}

	Filesystem & Filesystem::getMutableInstance(void)
	{
		return *instance;
	}
};