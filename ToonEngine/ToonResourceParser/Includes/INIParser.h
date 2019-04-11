#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <unordered_map>
#include <optional>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace ToonResourceParser
{
	class INISection
	{
	public:
		using storage_t = std::unordered_map<std::string, std::string>;

		INISection() = default;

		void addData(std::string const&, std::string const&) noexcept;
		std::optional<std::string> getData(std::string const&) const noexcept;
	private:
		storage_t storage{};
	};

	class INIParser
	{
	public:
		using storage_t = std::unordered_map<std::string, INISection>;

		INIParser() = default;
		INIParser(std::string const&) noexcept;
		bool open(std::string const&) noexcept;

		template <typename Type>
		std::optional<Type> getData(std::string const&) const noexcept;
	private:
		storage_t storage{};
	};

	template <typename Type>
	std::optional<Type> INIParser::getData(std::string const& name) const noexcept
	{
		auto offset = name.find_first_of('.');
		std::string secName = name.substr(0, offset);  // split section  name from whole input string
		std::string varName = name.substr(offset + 1); // split variable name from whole input string

		auto iter = storage.find(secName);
		if (iter == end(storage)) return {};

		auto const& section = iter->second;
		auto tempData = section.getData(varName);
		
		if (!tempData) return {};

		std::string stringData = tempData.value();
		Type retData{};

		if constexpr (std::is_integral_v<Type>)
		{
			std::size_t integral = std::stoll(stringData);
			retData = static_cast<Type>(integral);
		}
		else if constexpr (std::is_floating_point_v<Type>)
		{
			long double real = std::stold(stringData);
			retData = static_cast<Type>(real);
		}
		else
		{
			auto firstQuotesLoc = stringData.find_first_of('"');
			auto secondQuotesLoc = stringData.find_last_of('"');
			retData = stringData.substr(firstQuotesLoc + 1, secondQuotesLoc - firstQuotesLoc - 1);
		}

		return retData;
	}

	void INISection::addData(std::string const& name, std::string const& data) noexcept
	{
		storage.insert(std::make_pair(name, data));
	}

	std::optional<std::string> INISection::getData(std::string const& name) const noexcept
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
			return line.find('[') == 0;
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
					auto lastBracketLoc = line.find(']');

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

#endif