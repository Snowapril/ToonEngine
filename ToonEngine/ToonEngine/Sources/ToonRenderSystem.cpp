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
	bool RenderSystem::initWindow(INIParser const &) noexcept
	{
		return true;
	}
};