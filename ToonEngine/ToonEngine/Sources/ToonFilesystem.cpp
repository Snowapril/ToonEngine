#include "stdafx.h"
#include "ToonFilesystem.h"
#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include <iostream>

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include <fmt/format.h>

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
		if (Logger::isDestroyed())
		{
			auto releaseInfo = fmt::format(OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("FileSystem instance is released"), reinterpret_cast<void*>(instance));
			std::clog << releaseInfo << std::endl;
		}
		else
		{
			Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("FileSystem instance is released"), reinterpret_cast<void*>(instance));
		}
	}

	void Filesystem::setDirectory( std::string const & label, std::string const & directory )
	{
		dirTable[label] = directory;
	}

	std::string Filesystem::getRootPath(void) const
	{
		return rootPath;
	}

	std::string Filesystem::getAbsolutePath(std::string const& filename) const
	{
		return rootPath + filename;
	}

	bool Filesystem::isExists(std::string const & relativePath, fs::file_status s) const
	{
		std::string absPath = rootPath + relativePath;
		auto filePath = fs::path(absPath);
		
		return fs::status_known(s) ? fs::exists(s) : fs::exists(filePath);
	}
	void Filesystem::createDirectory(std::string const & relativePath) const
	{	
		std::string absPath = rootPath + relativePath;
		auto fileePath = fs::path(absPath);

		std::error_code ec;
		bool result = fs::create_directory(absPath, ec);
		if (!result) std::cerr << ec.message() << std::endl;
	}
};