#ifndef TOON_GL3_PLUS_ERROR_CODES_H
#define TOON_GL3_PLUS_ERROR_CODES_H

#include <string>

namespace ToonGL3Plus
{
	/****************************************************************************
				RenderSystem error handling functions here declaration
	****************************************************************************/
	enum class RenderSystemErrorCodes : unsigned int
	{
		UNKNOWN_UNIFORM_VARIABLE_NAME = 0x00000000,
		UNKNOWN_UNIFORM_VARIABLE_TYPE = 0x00000001
	};

	std::string getErrorString(RenderSystemErrorCodes code)
	{
		std::string errorString;

		switch (code)
		{
		case RenderSystemErrorCodes::UNKNOWN_UNIFORM_VARIABLE_NAME:
			errorString = "Unknown uniform variable name";
			break;
		case RenderSystemErrorCodes::UNKNOWN_UNIFORM_VARIABLE_TYPE:
			errorString = "Unknown uniform variable type";
			break;
		default:
			errorString = "Unknown rendering system error code";
			break;
		}

		return errorString;
	}
};	 


#endif