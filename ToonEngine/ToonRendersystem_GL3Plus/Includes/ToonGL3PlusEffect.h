#ifndef EFFECT_H
#define EFFECT_H

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusEffect class declaration
	****************************************************************************/
	class GL3PlusEffect
	{
	private:
		int effect;
	public:
		GL3PlusEffect();
		~GL3PlusEffect();

		int 		compileProgram(const char* effectFilePath, const char* programName) const;
		const char* getProgramName(int programIndex) const;
	private:
		void		handleGLFXError(void) const;
	};
};

#endif