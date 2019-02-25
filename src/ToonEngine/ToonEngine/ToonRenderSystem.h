#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include <string>

struct GLFWwindow;

namespace Toon
{
	class ToonRenderSystem : public ToonNoncopyable
	{
	private:
		std::string windowTitle;
		GLFWwindow *window = nullptr;
		int			clientWidth = 0;
		int			clientHeight = 0;
		bool        bFullscreen = false;
	public:
		ToonRenderSystem();
		~ToonRenderSystem();
	public:
		GLFWwindow const* getAppWindow	(void)	const { return window; }
		float			  getAspectRatio(void)	const { return static_cast<float>(clientWidth) / clientHeight; }
	};
};

#include "ToonHeaderPostfix.h"

#endif