#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <unordered_map>
#include <optional>
#include <string>

namespace ToonResourceParser
{
	class INISection
	{
	public:
		using storage_t = std::unordered_map<std::string, std::string>;

		INISection() = default;

		void addData(std::string const&, std::string const&) noexcept;
		std::optional<std::string> const& getData(std::string const&) const noexcept;
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

		if constexpr (std::enable_if_t<std::is_integral_v<Type>>)
		{
			std::size_t integral = std::stoll(stringData);
			retData = static_cast<Type>(integral);
		}
		else if constexpr (std::enable_if_t<std::is_floating_point_v<Type>>)
		{
			long double real = std::stold(stringData);
			retData = static_cast<Type>(real);
		}
		else
		{
			auto firstQuotesLoc = stringData.find_first_of('"');
			auto secondQuotesLoc = stringData.find_last_of('"');
			retData = stringData.substr(firstQuotesLoc, secondQuotesLoc - firstQuotesLoc);
		}

		return retData;
	}
};

#endif