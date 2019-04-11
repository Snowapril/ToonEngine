#include "INIParser.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace ToonResourceParser
{
	void INISection::addData(std::string const& name, std::string const& data) noexcept
	{
		storage.insert(std::make_pair(name, data));
	}

	std::optional<std::string> const& INISection::getData(std::string const& name) const noexcept
	{
		auto iter = storage.find(name);

		if (iter == end(storage)) return {};
		else					  return iter->second;
	}

	INIParser::INIParser(std::string const& path) noexcept
	{
		assert(open(path));
	}

	bool INIParser::open(std::string const& path) noexcept
	{
		std::ifstream iniFile(path);

		auto isSectionName = [](std::string const& line)
		{
			return line.find('[') != line.size();
		};

		if (iniFile.is_open())
		{
			INISection section;
			std::string sectionName{};
			std::string line{};

			while (iniFile >> line)
			{
				bool bSection = isSectionName(line);

				if (bSection)
				{
					if (!sectionName.empty())
					{
						storage[sectionName] = section;
						section = INISection();
					}
					auto lastBracketLoc  = line.find(']');
					
					if (lastBracketLoc == line.size())
					{
						iniFile.close();
						return false;
					}

					sectionName = line.substr(1, lastBracketLoc - 1);
				}
				else
				{
					auto equalLoc = line.find('=');
					if (equalLoc == line.size())
					{
						iniFile.close();
						return false;
					}

					std::string name = line.substr(0, equalLoc);
					std::string data = line.substr(equalLoc + 1);
					section.addData(name, data);
				}
			}

			if (!sectionName.empty()) storage[sectionName] = section;
			iniFile.close();
		}
		else
		{
			return false;
		}

		return true;
	}
};