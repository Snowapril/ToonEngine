#include "stdafx.h"
#include "ToonParser.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace boost::property_tree;

namespace Toon
{
	INIParser::INIParser(std::string const &path)
	{
		ini_parser::read_ini(path, iniParser);
	}

	JsonParser::JsonParser(std::string const &path)
	{
		json_parser::read_json(path, jsonParser);
	}

	decltype(auto) JsonParser::getSubtree(std::string const &symbolName) const
	{
		return jsonParser.get_child_optional(symbolName);
	}

};
