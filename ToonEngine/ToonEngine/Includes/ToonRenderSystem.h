#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include <ToonGL3PlusRendersystem.h>
#include <string>
#include <INIParser.h>

struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						RenderSystem class declaration
	****************************************************************************/
	class RenderSystem : public ToonGL3Plus::GL3PlusRenderSystem
	{
		using super_t = ToonGL3Plus::GL3PlusRenderSystem;
	public:
		RenderSystem() noexcept;
		~RenderSystem() noexcept;
	public:
		void preDrawScene(void) const noexcept;
		void drawScene	 (void) const noexcept;

		bool initWindow	(ToonResourceParser::INIParser const&) noexcept;
	};
};

#include "ToonHeaderPostfix.h"

#endif