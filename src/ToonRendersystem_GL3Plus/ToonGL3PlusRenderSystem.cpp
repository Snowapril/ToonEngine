// ToonRendersystem_GL3Plus.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"


namespace ToonGL3Plus
{
	bool ToonRoot::initContext(int width, int height, char const *wndTitle, bool fullscreen)
	{
		if (!glfwInit())
		{
			Logger::getConstInstance().errorMessage(OBFUSCATE("GLFW initialization failed."));
			return false;
		}

		this->windowTitle = wndTitle;
		this->clientWidth = width;
		this->clientHeight = height;
		this->bFullscreen = fullscreen;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ 
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

		GLFWmonitor		  *glfwMonitor = glfwGetPrimaryMonitor();
		GLFWvidmode const *glfwMode = glfwGetVideoMode(glfwMonitor);

		glfwWindowHint(GLFW_RED_BITS, glfwMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, glfwMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, glfwMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, glfwMode->refreshRate);
		glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

		if (bFullscreen)
		{
			clientWidth = glfwMode->width;
			clientHeight = glfwMode->height;
		}
		else
		{
			glfwMonitor = nullptr;
		}

		window = glfwCreateWindow(clientWidth, clientHeight, wndTitle, glfwMonitor, nullptr);

		if (!window)
		{
			glfwTerminate();
			Logger::getConstInstance().errorMessage(OBFUSCATE("GLFW Window Creating failed."));
			return false;
		}


		glfwMakeContextCurrent(window);

		int e = glewInit();
		if (e != GLEW_OK)
		{
			Logger::getConstInstance().errorMessage("Failed to init GLEW\nError{}", glewGetErrorString(e));
			return false;
		}

#define CHECK_EXTENSION(ext) if(!glewGetExtension("GL_ARB_"#ext)){ ToonLogger::getConstInstance().errorMessage( "GLEW: GL_ARB_{} not supported.\n", #ext ); return false; }
		CHECK_EXTENSION(shading_language_100);	// check your platform supports GLSL
		CHECK_EXTENSION(vertex_buffer_object);	// BindBuffers, DeleteBuffers, GenBuffers, IsBuffer, BufferData, BufferSubData, GenBufferSubData, ...
		CHECK_EXTENSION(vertex_shader);			// functions related to vertex shaders
		CHECK_EXTENSION(fragment_shader);			// functions related to fragment shaders
		CHECK_EXTENSION(shader_objects);			// functions related to program and shaders
#undef CHECK_EXTENSION

		const GLubyte* vendor = glGetString(GL_VENDOR);
		const GLubyte* renderer = glGetString(GL_RENDERER);

		Logger::getConstInstance().infoMessage(OBFUSCATE("Vendor : {:<15}, Renderer : {:<15}"), vendor, renderer);

		registerCallback();

		return true;
	}
};