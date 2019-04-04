#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonEngineSystem.h"
#include "ToonPrerequisites.h"
#include <string>

struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						RenderSystem class declaration
	****************************************************************************/
	class RenderSystem : public EngineSystem
	{
	private:
		std::string windowTitle;
		int			clientWidth = 0;
		int			clientHeight = 0;
		bool        bFullscreen = false;
	public:
		RenderSystem();
		~RenderSystem();
	public:
		void preDrawScene(void) const noexcept;
		void drawScene	 (void) const noexcept;
	public:
		bool			  initWindow	(INIParser const&) noexcept;
		float			  getAspectRatio(void)	const { return static_cast<float>(clientWidth) / clientHeight; }
	};
};

#include "ToonHeaderPostfix.h"

#endif