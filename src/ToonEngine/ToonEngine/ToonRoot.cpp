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

	bool ToonRoot::initContext( int width, int height, char const *wndTitle, bool fullscreen )
	{
		if (!glfwInit())
		{
			Logger::getConstInstance().errorMessage( OBFUSCATE("GLFW initialization failed.") );
			return false;
		}

		this->windowTitle = wndTitle;
		this->clientWidth = width;
		this->clientHeight = height;
		this->bFullscreen = fullscreen;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4				);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3				);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4								);

#ifdef __APPLE__ 
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

		GLFWmonitor		  *glfwMonitor = glfwGetPrimaryMonitor();
		GLFWvidmode const *glfwMode = glfwGetVideoMode(glfwMonitor);

		glfwWindowHint(GLFW_RED_BITS,		glfwMode->redBits		);
		glfwWindowHint(GLFW_GREEN_BITS,		glfwMode->greenBits		);
		glfwWindowHint(GLFW_BLUE_BITS,		glfwMode->blueBits		);
		glfwWindowHint(GLFW_REFRESH_RATE,	glfwMode->refreshRate	);
		glfwWindowHint(GLFW_SRGB_CAPABLE,	GLFW_TRUE				);

		if (bFullscreen)
		{
			clientWidth  = glfwMode->width;
			clientHeight = glfwMode->height;
		}
		else
		{
			glfwMonitor = nullptr;
		}

		window = glfwCreateWindow( clientWidth, clientHeight, wndTitle, glfwMonitor, nullptr );

		if (!window)
		{
			glfwTerminate();
			Logger::getConstInstance().errorMessage( OBFUSCATE("GLFW Window Creating failed.") );
			return false;
		}


		glfwMakeContextCurrent(window);

		int e = glewInit();
		if (e != GLEW_OK)
		{
			Logger::getConstInstance().errorMessage( "Failed to init GLEW\nError{}", glewGetErrorString(e) );
			return false;
		}

#define CHECK_EXTENSION(ext) if(!glewGetExtension("GL_ARB_"#ext)){ ToonLogger::getConstInstance().errorMessage( "GLEW: GL_ARB_{} not supported.\n", #ext ); return false; }
		CHECK_EXTENSION(shading_language_100);	// check your platform supports GLSL
		CHECK_EXTENSION(vertex_buffer_object);	// BindBuffers, DeleteBuffers, GenBuffers, IsBuffer, BufferData, BufferSubData, GenBufferSubData, ...
		CHECK_EXTENSION(vertex_shader);			// functions related to vertex shaders
		CHECK_EXTENSION(fragment_shader);			// functions related to fragment shaders
		CHECK_EXTENSION(shader_objects);			// functions related to program and shaders
#undef CHECK_EXTENSION

		const GLubyte* vendor	= glGetString(GL_VENDOR);
		const GLubyte* renderer = glGetString(GL_RENDERER);

		Logger::getConstInstance().infoMessage( OBFUSCATE("Vendor : {:<15}, Renderer : {:<15}"), vendor, renderer );

		registerCallback();

		return true;
	}

	void ToonRoot::release(void)
	{
		glfwTerminate();
	}

	bool ToonRoot::reset(void)
	{
		return false;
	}

	void ToonRoot::registerCallback(void)
	{
		glfwSetKeyCallback				(window, localKeyCallback					);
		glfwSetMouseButtonCallback		(window, localMouseBtnCallback				);
		glfwSetCursorPosCallback		(window, localMousePosCallback				);
		glfwSetFramebufferSizeCallback	(window, localResizingCallback				);
		glfwSetScrollCallback			(window, localScrollCallback				);
		glfwSetInputMode				(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED	);
	}

	int ToonRoot::runApplicationLoop(void)
	{
		//timer reset
		timer->reset();
		int count = 0;
		
		initialUpdate();

		while (!glfwWindowShouldClose(window))
		{
			timer->tick();
			
			float dt		= timer->getDeltaTime();
			float totalTime = timer->getTotalTime();

			updateScene(dt);

			drawScene();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		return 0;
	}

	void ToonRoot::resizingCallback( int newWidth, int newHeight )
	{
		glViewport( 0, 0, newWidth, newHeight );
	}

	ToonRoot const & ToonRoot::getConstInstance(void)
	{
		return *instance;
	}

	ToonRoot & ToonRoot::getMutableInstance(void)
	{
		return *instance;
	}

	void localKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
	{
		Singleton<ToonRoot>::getMutableInstance().keyCallback( key, scancode, action, mode );
	}

	void localMousePosCallback( GLFWwindow* window, double xpos, double ypos )
	{
		Singleton<ToonRoot>::getMutableInstance().mousePosCallback( xpos, ypos );
	}

	void localMouseBtnCallback( GLFWwindow* window, int btn, int action, int mods )
	{
		Singleton<ToonRoot>::getMutableInstance().mouseBtnCallback( btn, action, mods );
	}

	void localScrollCallback( GLFWwindow* window, double xoffset, double yoffset )
	{
		Singleton<ToonRoot>::getMutableInstance().scrollCallback( xoffset, yoffset );
	}

	void localResizingCallback( GLFWwindow* window, int newWidth, int newHeight )
	{
		if (newWidth  == 0) newWidth  = 1;
		if (newHeight == 0) newHeight = 1;

		Singleton<ToonRoot>::getMutableInstance().resizingCallback( newWidth, newHeight );
	}
};