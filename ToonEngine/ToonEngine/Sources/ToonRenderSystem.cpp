#include "stdafx.h"
#include "ToonRenderSystem.h"

#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"

namespace Toon
{
	/****************************************************************************
						RenderSystem class definition
	****************************************************************************/
	using namespace ToonResourceParser;

	RenderSystem::RenderSystem()
	{
	}
	RenderSystem::~RenderSystem()
	{
	}
	void RenderSystem::preDrawScene(void) const noexcept
	{
		super_t::preDrawScene();
	}
	void RenderSystem::drawScene(void) const noexcept
	{
		super_t::drawScene();
	}
	bool RenderSystem::initWindow(INIParser const & parser) noexcept
	{
		auto width  = parser.getData<int>("Rendersystem.client_width");
		auto height = parser.getData<int>("Rendersystem.client_height");
		auto title  = parser.getData<char const*>("Rendersystem.window_title");

		if (AnyOf(!width, !height, !title)) return false;

		if (!super_t::initWindow(title.value(), width.value(), height.value()))
			return false;

		return true;
	}
};