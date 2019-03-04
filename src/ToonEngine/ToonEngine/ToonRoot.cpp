#include "stdafx.h"
#include "ToonRoot.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ToonLogger.h"
#include "ToonObfuscator.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"

namespace Toon
{
	template <> ToonRoot* Singleton<ToonRoot>::instance = nullptr;

	// local callback functions declaration
	void localKeyCallback		( GLFWwindow* window, int key, int scancode, int action, int mode );
	void localMousePosCallback	( GLFWwindow* window, double xpos, double ypos );
	void localMouseBtnCallback	( GLFWwindow* window, int btn, int action, int mods );
	void localScrollCallback	( GLFWwindow* window, double xoffset, double yoffset );
	void localResizingCallback	( GLFWwindow* window, int newWidth, int newHeight );

	ToonRoot::ToonRoot()
		: timer()
	{
	}

	ToonRoot::~ToonRoot()
	{
		Logger::getConstInstance().infoMessage( "[Singleton] Application instnace is released ({0:x})", reinterpret_cast<void*>(instance) );
		release();
	}

	bool ToonRoot::initialize(bool autoCreateWindow, std::string const & windowTitle, std::string const & configFilePath)
	{
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
	}

	void ToonRoot::drawScene(void) const
	{
	}

	void ToonRoot::release(void)
	{
		glfwTerminate();
	}

	int ToonRoot::runMainLoop(void)
	{
		//timer reset
		timer->reset();
		int count = 0;
		
		initialUpdate();

		while (true)
		{
			timer->tick();
			float dt		= timer->getDeltaTime();
			float totalTime = timer->getTotalTime();

			preUpdateScene(dt);
			updateScene(dt);
			preDrawScene();
			drawScene();
		}

		release();

		return 0;
	}

	ToonRoot const & ToonRoot::getConstInstance(void)
	{
		return *instance;
	}

	ToonRoot & ToonRoot::getMutableInstance(void)
	{
		return *instance;
	}
};