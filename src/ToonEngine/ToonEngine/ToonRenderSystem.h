#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonSystem.h"
#include "ToonPrerequisites.h"
#include <string>

struct GLFWwindow;

namespace Toon
{
	class RenderSystem : public EngineSystem
	{
	private:
		std::string windowTitle;
		GLFWwindow *window = nullptr;
		int			clientWidth = 0;
		int			clientHeight = 0;
		bool        bFullscreen = false;
	public:
		RenderSystem();
		~RenderSystem();
	public:
		void handleSystemMessage(ToonSystemMessage const & msg) override;

		GLFWwindow const* getAppWindow	(void)	const { return window; }
		float			  getAspectRatio(void)	const { return static_cast<float>(clientWidth) / clientHeight; }
	};
};

#include "ToonHeaderPostfix.h"

#endif