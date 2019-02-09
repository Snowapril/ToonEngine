#include "stdafx.h"
#include "FileSystem.h"

std::shared_ptr<FileSystem> Singleton<FileSystem>::instance(new FileSystem());

void FileSystem::addDirectory(const std::string& label, const std::string& directory)
{
	dirTable[label] = directory;
}

std::string FileSystem::getRootPath(void) const
{
	return rootPath;
}

std::string FileSystem::getRelativePath(const std::string& label, const std::string& filename) const
{
	std::string retPath;
	
	if (dirTable.find(label) != dirTable.end()) 
		retPath = dirTable.at(label) + filename;

	return retPath;
}