#include "stdafx.h"
#include "ToonFilesystem.h"
#include "ToonLogger.h"
#include <filesystem>

namespace Toon
{
	/****************************************************************************
						Filesystem class definition
	****************************************************************************/
	template <> Filesystem* Singleton< Filesystem >::instance = nullptr;
	namespace fs = std::experimental::filesystem;

	Filesystem::Filesystem( std::string const & rootPath )
		: rootPath(rootPath)
	{
	}

	Filesystem::~Filesystem()
	{
		Logger::getConstInstance().infoMessage( OBFUSCATE("[Singleton] FileSystem instnace is released ({0:x})"), reinterpret_cast<void*>(instance) );
	}

	void Filesystem::setDirectory( const std::string& label, const std::string& directory )
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
	bool Filesystem::isExists(std::string const & relativePath) const
	{
		return fs::exists(rootPath + relativePath);
	}
	void Filesystem::createDirectory(std::string const & relativePath) const
	{
		fs::create_directory(rootPath + relativePath);
	}
};