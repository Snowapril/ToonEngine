#include "stdafx.h"
#include "ToonParser.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <filesystem>
#include <sstream>

#include "ToonExceptions.h"

using namespace boost::property_tree;

namespace Toon
{
	namespace fs = std::experimental::filesystem;

	INIParser::INIParser(std::string const &path)
	{
		std::stringstream sstr;
		sstr << "ini file not exists : " << path;
		ToonAssert(sstr.str(), open(path));
	}

	bool INIParser::open(std::string const &path)
	{
		if (fs::exists(path))
		{
			ini_parser::read_ini(path, iniParser);
			return true;
		}
		else
		{
			return false;
		}
	}

	JsonParser::JsonParser(std::string const &path)
	{
		std::stringstream sstr;
		sstr << "json file not exists : " << path;
		ToonAssert(sstr.str(), open(path));
	}

	decltype(auto) JsonParser::getSubtree(std::string const &symbolName) const
	{
		return jsonParser.get_child_optional(symbolName);
	}


	bool JsonParser::open(std::string const& path)
	{
		if (fs::exists(path))
		{
			json_parser::read_json(path, jsonParser);
			return true;
		}
		else
		{
			return false;
		}
	}
};
