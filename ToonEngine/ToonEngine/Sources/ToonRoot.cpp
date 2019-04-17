#include "stdafx.h"
#include "ToonRoot.h"

#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"
#include "ToonRenderSystem.h"
#include "ToonSystemMessageBus.h"
#include "ToonSystemMessage.h"
#include "ToonExceptions.h"
#include "ToonInputSystem.h"

#include <algorithm>

namespace Toon
{
	/****************************************************************************
				ToonRoot class definition
	****************************************************************************/
	template <> ToonRoot* Singleton<ToonRoot>::instance = nullptr;
	using namespace ToonResourceParser;

	// local callback functions declaration
	void localKeyCallback		( GLFWwindow* window, int key, int scancode, int action, int mode ) {};
	void localMousePosCallback	( GLFWwindow* window, double xpos, double ypos ) {};
	void localMouseBtnCallback	( GLFWwindow* window, int btn, int action, int mods ) {};
	void localScrollCallback	( GLFWwindow* window, double xoffset, double yoffset ) {};
	void localResizingCallback	( GLFWwindow* window, int newWidth, int newHeight ) {};

	ToonRoot::ToonRoot()
	{
		instance = this;
	}

	ToonRoot::~ToonRoot()
	{
		Logger::getConstInstance().infoMessage( OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("ToonRoot instance is released"), reinterpret_cast<void*>(instance) );
		release();
	}	

	bool ToonRoot::initialize(bool autoCreateWindow, std::string const & windowTitle, std::string const & configFilePath)
	{
		INIParser parser(configFilePath);

		if (autoCreateWindow)
		{
			

		}
		else
		{

		}

		if (!initSubsystems(parser))
			return false;

		return true;
	}

	bool ToonRoot::initSubsystems(INIParser const& parser)
	{
		auto rootPath = parser.getData<std::string>("Common.root_path");
		auto logPath  = parser.getData<std::string>("Common.log_path");

		if (AnyOf(!rootPath, !logPath)) return false;

		if (Filesystem::isDestroyed())
		{
			filesystem.reset(new Filesystem(rootPath.value())); 
		}

		if (Logger::isDestroyed())
		{
			logger.reset(new Logger(logPath.value()));
		}

		if (Timer::isDestroyed())
		{
			timer.reset(new Timer());
		}

		if (SystemMessageBus::isDestroyed())
		{
			systemMessageBus.reset(new SystemMessageBus());
		}

		if (InputSystem::isDestroyed())
		{
			inputSystem.reset(new InputSystem());
		}
		
		if (RenderSystem::isDestroyed())
		{
			renderSystem.reset(new RenderSystem());
			if (!renderSystem->initWindow(parser)) return false;
		}

		return true;
	}

	void ToonRoot::initialUpdate(void)
	{
	}

	void ToonRoot::preUpdateScene(float dt)
	{
	}

	void ToonRoot::updateScene(float dt)
	{
	}

	void ToonRoot::preDrawScene(void) const
	{
		renderSystem->preDrawScene();
	}

	void ToonRoot::drawScene(void) const
	{
		renderSystem->drawScene();
	}

	void ToonRoot::release(void)
	{
		// releasing order must be exactly reverse of initialization order
		renderSystem.reset();
		inputSystem.reset();
		systemMessageBus.reset();
		timer.reset();
		logger.reset();
		filesystem.reset();
	}

	int ToonRoot::runMainLoop(void)
	{
		//timer reset
		timer->reset();
		
		initialUpdate();

		while (true)
		{
			timer->tick();
			float dt		= timer->getDeltaTime();
			float totalTime = timer->getTotalTime();

			logger->infoMessage("delta time {0:01.4f} ms, total time {1:04.3f} sec", dt * 1000.0f, totalTime);

			if (timer->isPaused())
			{
				// sleep here (cross-platform)
			}
			else
			{
				preUpdateScene(dt); // 1) pre-simulation step
				updateScene(dt);    // 2) simulation	 step
				preDrawScene();	    // 3) pre-draw		 step
				drawScene();	    // 4) darw  		 step
			}
		}

		return 0;
	}
};