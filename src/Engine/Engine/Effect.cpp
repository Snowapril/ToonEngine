#include "stdafx.h"
#include "Effect.h"
#include <GLFX/glfx.h>
#include "Logger.h"

namespace Toon
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
		Logger::getConstInstance().errorMessage(errorLog);
	}
};