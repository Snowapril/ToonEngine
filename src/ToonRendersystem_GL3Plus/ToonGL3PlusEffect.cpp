#include "stdafx.h"
#include "ToonGL3PlusEffect.h"
#include <GLFX/glfx.h>
#include <ToonEngine/ToonLogger.h>

namespace ToonGL3Plus
{
	Effect::Effect()
	{
		effect = glfxGenEffect();
	}

	Effect::~Effect()
	{
		glfxDeleteEffect(effect);
	}

	int Effect::compileProgram( const char * effectFilePath, const char * programName ) const
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

	const char* Effect::getProgramName( int programIndex ) const
	{
		return glfxGetProgramName( effect, programIndex );
	}

	void Effect::handleGLFXError(void) const
	{
		std::string errorLog = glfxGetEffectLog(effect);
		ToonLogger::getConstInstance().errorMessage(errorLog);
	}
};