#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <unordered_map>
#include <optional>
#include <string>
#include <cassert>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace ToonResourceParser
{
	class INISection
	{
	public:
		using storage_t = std::unordered_map<std::string, std::string>;

		INISection() = default;

		void addData(std::string const& name, std::string const& data) noexcept
		{
			storage.insert(std::make_pair(name, data));
		}
		std::optional<std::string> getData(std::string const& name) const noexcept
		{
			auto iter = storage.find(name);

			if (iter == end(storage)) return {};
			else					  return iter->second;
		}
	private:
		storage_t storage{};
	};

	class INIParser
	{
	public:
		using storage_t = std::unordered_map<std::string, INISection>;

		INIParser() = default;
		INIParser(std::string const& path)
		{
			namespace fs = std::filesystem;

			if (!open(path))
			{
				std::cerr << "Cannot find path with [ " << fs::absolute(path) << " ] " << std::endl;
				std::terminate();
			}
		}
		bool open(std::string const& path) noexcept
		{
			std::ifstream iniFile(path);
			if (iniFile.is_open() == false) return false;

			INISection section;
			std::string sectionName{};
			std::string line{};

			while (std::getline(iniFile, line))
			{
				if (line.empty()) continue;

				if (line.find('[') == 0) // check whether if the given line is section name or not.
				{
					if (!sectionName.empty())
					{
						storage[sectionName] = section;
						section = INISection();
					}
					sectionName = line.substr(1, line.length() - 2);
				}
				else // otherwise, given line will be variable name and value enclosed to section name.
				{
					auto equalLoc = line.find('=');
					if (equalLoc == std::string::npos)
					{
						iniFile.close();
						return false;
					}
					std::string name = line.substr(0, equalLoc);
					std::string data = line.substr(equalLoc + 1);

					name.erase(std::remove_if(begin(name), end(name), ::isspace), end(name)); // remove blank space in the name.

					section.addData(name, data);
				}
			} // end of file

			if (!sectionName.empty()) storage[sectionName] = section;
			iniFile.close();
			return true;
		}

		template <typename Type>
		std::optional<Type> getData(std::string const& name) const noexcept
		{
			return {};
		}
		template <>
		std::optional<int> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string strData = originalData.value();
			strData.erase(std::remove_if(begin(strData), end(strData), ::isspace), end(strData)); // remove blank space in the name.
			return std::stoi(strData);
		}
		template <>
		std::optional<std::string> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string stringData = originalData.value();
			auto firstQuotesLoc = stringData.find_first_of('"');
			auto secondQuotesLoc = stringData.find_last_of('"');
			return stringData.substr(firstQuotesLoc + 1, secondQuotesLoc - firstQuotesLoc - 1);
		}
		template <>
		std::optional<double> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string strData = originalData.value();
			strData.erase(std::remove_if(begin(strData), end(strData), ::isspace), end(strData)); // remove blank space in the name.
			return std::stod(strData);
		}
		template <>
		std::optional<bool> getData(std::string const& name) const noexcept
		{
			auto originalData = getOriginalData(name);
			if (!originalData) return {};
			std::string boolString = originalData.value();
			boolString.erase(std::remove_if(begin(boolString), end(boolString), ::isspace), end(boolString)); // remove blank space in the name.
			return boolString == "true" || boolString == "TRUE";
		}
		private:
			std::optional<std::string> getOriginalData(std::string const & name) const noexcept
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
				return stringData;
			}
	private:
		storage_t storage{};
	};
};

#endif