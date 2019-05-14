/**
 * @file ToonGL3PlusEffect.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide useful methods such as compiling GLSL binary file (What DirectX is doing)
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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