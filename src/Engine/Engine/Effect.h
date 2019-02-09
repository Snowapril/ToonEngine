#ifndef EFFECT_H
#define EFFECT_H

class Effect
{
private:
	int effect;
public:
	Effect();
	~Effect();

	int 		compileProgram(const char *effectFilePath, const char *programName) const;
	const char* getProgramName(int programIndex) const;
private:
	void		handleGLFXError(void) const;
};

#endif