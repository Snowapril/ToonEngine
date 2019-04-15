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
	class RenderSystem : public ToonGL3Plus::GL3PlusRendersystem
	{
		using super_t = ToonGL3Plus::GL3PlusRendersystem;
	private:
		static RenderSystem* instance;
	public:
		RenderSystem();
		~RenderSystem();

		static RenderSystem const& getConstInstance(void);
		static RenderSystem& getMutableInstance(void);
		static bool isDestroyed(void) { return instance == nullptr; }
	public:
		void preDrawScene(void) const noexcept;
		void drawScene	 (void) const noexcept;

		bool initWindow	(ToonResourceParser::INIParser const&) noexcept;
	};
};

#include "ToonHeaderPostfix.h"

#endif