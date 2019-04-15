#include "stdafx.h"
#include "ToonRenderSystem.h"

#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"
#include "ToonExceptions.h"

namespace Toon
{
	/****************************************************************************
						RenderSystem class definition
	****************************************************************************/
	using namespace ToonResourceParser;
	RenderSystem* RenderSystem::instance = nullptr;
	
	RenderSystem::RenderSystem()
	{
		assert(instance == nullptr);
	}
	RenderSystem::~RenderSystem()
	{
		assert(instance != nullptr);
	}
	RenderSystem const& RenderSystem::getConstInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
	}
	RenderSystem& RenderSystem::getMutableInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
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
		auto title  = parser.getData<std::string>("Rendersystem.window_title");

		if (AnyOf(!width, !height, !title)) return false;

		if (!super_t::initWindow(title.value(), width.value(), height.value()))
			return false;

		return true;
	}
};