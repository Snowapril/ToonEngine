#include "stdafx.h"
#include "ToonEffect.h"
#include <GLFX/glfx.h>
#include "ToonLogger.h"

namespace Toon
{
	ToonEffect::ToonEffect()
	{
		effect = glfxGenEffect();
	}

	ToonEffect::~ToonEffect()
	{
		glfxDeleteEffect(effect);
	}

	int ToonEffect::compileProgram( const char * effectFilePath, const char * programName ) const
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

	const char* ToonEffect::getProgramName( int programIndex ) const
	{
		return glfxGetProgramName( effect, programIndex );
	}

	void ToonEffect::handleGLFXError(void) const
	{
		std::string errorLog = glfxGetEffectLog(effect);
		ToonLogger::getConstInstance().errorMessage(errorLog);
	}
};