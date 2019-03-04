#include "stdafx.h"
#include "ToonGL3PlusEffect.h"
#include <GLFX/glfx.h>
#include <ToonEngine/ToonLogger.h>

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusEffect class definition
	****************************************************************************/
	GL3PlusEffect::GL3PlusEffect()
	{
		effect = glfxGenEffect();
	}

	GL3PlusEffect::~GL3PlusEffect()
	{
		glfxDeleteEffect(effect);
	}

	int GL3PlusEffect::compileProgram( const char * effectFilePath, const char * programName ) const
	{
		bool bParsingSuccess = glfxParseEffectFromFile( effect, effectFilePath );
		if (!bParsingSuccess)
		{
			handleGLFXError();
			return -1;
		}

		int program = glfxCompileProgram( effect, programName );
		if (program == -1)
		{
			handleGLFXError();
			return -1;
		}

		return program;
	}

	const char* GL3PlusEffect::getProgramName( int programIndex ) const
	{
		return glfxGetProgramName( effect, programIndex );
	}

	void GL3PlusEffect::handleGLFXError(void) const
	{
		std::string errorLog = glfxGetEffectLog(effect);
		Toon::Logger::getConstInstance().errorMessage(errorLog);
	}
};