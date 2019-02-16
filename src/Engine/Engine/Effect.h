#ifndef EFFECT_H
#define EFFECT_H

#include "ToonHeaderPrefix.h"

namespace Toon
{
	class Effect
	{
	private:
		int effect;
	public:
		Effect();
		~Effect();

		int 		compileProgram( const char *effectFilePath, const char *programName ) const;
		const char* getProgramName( int programIndex									) const;
	private:
		void		handleGLFXError(void) const;
	};
};

#include "ToonHeaderPostfix.h"

#endif