#ifndef TOON_PARSER_H
#define TOON_PARSER_H

#include <boost/property_tree/ptree.hpp>
#include <optional>


namespace Toon
{
	/****************************************************************************
						INIParser class  declaration
	****************************************************************************/
	class INIParser
	{
	private:
		boost::property_tree::ptree iniParser;
	public:
		INIParser(std::string const &);

		template <typename Type>
		boost::optional<Type> getData(std::string const &) const;
	};

	template <typename Type>
	boost::optional<Type> INIParser::getData(std::string const &symbolName) const
	{
		return iniParser.get_optional<Type>(symbolName);
	}

	/****************************************************************************
						JsonParser class  declaration
	****************************************************************************/
	class JsonParser
	{
	private:
		boost::property_tree::ptree jsonParser;
	public:
		JsonParser(std::string const &);

		template <typename Type>
		boost::optional<Type> getData(std::string const &) const;
		decltype(auto)	getSubtree(std::string const &) const;
	};

	template <typename Type>
	boost::optional<Type> JsonParser::getData(std::string const &symbolName) const
	{
		return jsonParser.get_optional<Type>(symbolName);
	}
};

#endif