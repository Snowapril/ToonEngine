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
		: super_t()
	{
		assert(instance == nullptr);
		instance = static_cast<RenderSystem*>(this);
	}
	RenderSystem::~RenderSystem()
	{
		Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("Rendersystem instance is released"), reinterpret_cast<void*>(instance));
		assert(instance != nullptr);
		instance = nullptr;
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
		auto width		= parser.getData<int>("Rendersystem.client_width");
		auto height		= parser.getData<int>("Rendersystem.client_height");
		auto title		= parser.getData<std::string>("Rendersystem.window_title");
		auto fullscreen = parser.getData<bool>("Rendersystem.default_fullscreen");

		if (AnyOf(!width, !height, !title, !fullscreen)) return false;

		auto initResult = super_t::initWindow(title.value(), width.value(), height.value(), fullscreen.value());
		if (initResult)
		{
			Logger::getConstInstance().errorMessage(OBFUSCATE("[Rendersystem] Initialization error occurred. {0}"), initResult.value());
			return false;
		}

		return true;
	}
};