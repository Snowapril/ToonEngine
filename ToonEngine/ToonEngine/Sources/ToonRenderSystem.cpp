#include "stdafx.h"
#include "ToonRenderSystem.h"

#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"
#include "ToonExceptions.h"

namespace Common
{
	template <> Toon::RenderSystem* Singleton<Toon::RenderSystem>::instance = nullptr;
}

namespace Toon
{
	/****************************************************************************
						RenderSystem class definition
	****************************************************************************/
	using namespace ToonResourceParser;

	RenderSystem::RenderSystem() noexcept
		: super_t()
	{
	}
	RenderSystem::~RenderSystem() noexcept
	{
		Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:>40} ({1:p})"), OBFUSCATE("Rendersystem instance is released"), reinterpret_cast<void*>(instance));
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
		auto width		= parser.getData<int>("RenderSystem.client_width");
		auto height		= parser.getData<int>("RenderSystem.client_height");
		auto title		= parser.getData<std::string>("RenderSystem.window_title");
		auto fullscreen = parser.getData<bool>("RenderSystem.default_fullscreen");

		if (AnyOf(!width, !height, !title, !fullscreen))
		{
			Logger::getConstInstance().errorMessage(OBFUSCATE("[RenderSystem] Resource Parsing Error Occurred."));
			return false;
		}

		auto initResult = super_t::initWindow(title.value(), width.value(), height.value(), fullscreen.value());
		if (initResult)
		{
			Logger::getConstInstance().errorMessage(OBFUSCATE("[RenderSystem] Initialization error occurred. {0}"), initResult.value());
			return false;
		}

		return true;
	}
};