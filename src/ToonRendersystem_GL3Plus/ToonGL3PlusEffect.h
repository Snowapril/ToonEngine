#ifndef EFFECT_H
#define EFFECT_H

#include <ToonEngine/ToonHeaderPrefix.h>

namespace ToonGL3Plus
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

#include <ToonEngine/ToonHeaderPostfix.h>

#endif