#include "stdafx.h"
#include "ToonFilesystem.h"
#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include <filesystem>
#include <iostream>

namespace Toon
{
	/****************************************************************************
						Filesystem class definition
	****************************************************************************/
	template <> Filesystem* Singleton< Filesystem >::instance = nullptr;
	namespace fs = std::filesystem;

	Filesystem::Filesystem( std::string const & rootPath )
		: rootPath(rootPath)
	{
	}

	Filesystem::~Filesystem()
	{
		Logger::getConstInstance().infoMessage( OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("FileSystem instance is released"), reinterpret_cast<void*>(instance) );
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
		std::error_code ec;
		bool result = fs::exists(rootPath + relativePath, ec);
		if (!result) std::cerr << ec.message() << std::endl;

		return result;
	}
	void Filesystem::createDirectory(std::string const & relativePath) const
	{	
		std::error_code ec;
		bool result = fs::create_directory(rootPath + relativePath, ec);
		if (!result) std::cerr << ec.message() << std::endl;
	}
};