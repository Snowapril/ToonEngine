#include "stdafx.h"
#include "ToonGL3PlusRendersystem.h"
#include <glew/glew.h>
#include <GLFW/glfw3.h>

#include "ToonGL3PlusInputSystem.h"

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include <fmt/format.h>

namespace Common
{
	template <> ToonGL3Plus::GL3PlusRenderSystem* Singleton<ToonGL3Plus::GL3PlusRenderSystem>::instance = nullptr;
}

namespace ToonGL3Plus
{
	using namespace Common;

	/****************************************************************************
						GL3PlusRenderSystem class definition
	****************************************************************************/
	namespace {
		ToonGL3Plus::GL3PlusRenderSystem* gInstance = nullptr;
	}

	GL3PlusRenderSystem::GL3PlusRenderSystem()
	{
		gInstance = this;
	}

	GL3PlusRenderSystem::GL3PlusRenderSystem(std::string const &title, int width, int height, bool fullscreen) noexcept
	{
		assert(!initWindow(title, width, height, fullscreen));
		gInstance = this;
	}
	GL3PlusRenderSystem::~GL3PlusRenderSystem() noexcept
	{
		glfwTerminate();
		gInstance = nullptr;
	}
	GLFWwindow const* GL3PlusRenderSystem::getWindow(void) const noexcept
	{
		return window;
	}
	double GL3PlusRenderSystem::getAspectRatio(void) const noexcept
	{
		return static_cast<double>(clientWidth) / clientHeight;
	}
	std::optional<std::string> GL3PlusRenderSystem::initWindow(std::string const &title, int width, int height, bool fullscreen) noexcept
	{
		if (!glfwInit())	
		{
			glfwTerminate();
			return "GLFW initialization failed.";
		}

		this->wndCaption	= title;
		this->clientWidth	= width;
		this->clientHeight	= height;
		this->fullscreen	= fullscreen;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ 
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

		GLFWmonitor* glfwMonitor = glfwGetPrimaryMonitor();
		GLFWvidmode const* glfwMode = glfwGetVideoMode(glfwMonitor);

		glfwWindowHint(GLFW_RED_BITS, glfwMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, glfwMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, glfwMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, glfwMode->refreshRate);
		glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

		if (fullscreen)
		{
			clientWidth = glfwMode->width;
			clientHeight = glfwMode->height;
		}
		else
		{
			glfwMonitor = nullptr;
		}

		window = glfwCreateWindow(clientWidth, clientHeight, title.c_str(), glfwMonitor, nullptr);

		if (!window)
		{
			glfwTerminate();
			return "GLFW Window Creating failed.";
		}


		glfwMakeContextCurrent(window);

		int e = glewInit();
		if (e != GLEW_OK)
		{
			glfwTerminate();
			return fmt::format("GLEW Error occurred {}", glewGetErrorString(e));
		}

#define CHECK_EXTENSION(ext) if(!glewGetExtension("GL_ARB_"#ext)){ glfwTerminate();return fmt::format( "GLEW: GL_ARB_{} not supported.\n", #ext ); }
		CHECK_EXTENSION(shading_language_100);	// check your platform supports GLSL
		CHECK_EXTENSION(vertex_buffer_object);	// BindBuffers, DeleteBuffers, GenBuffers, IsBuffer, BufferData, BufferSubData, GenBufferSubData, ...
		CHECK_EXTENSION(vertex_shader);			// functions related to vertex shaders
		CHECK_EXTENSION(fragment_shader);			// functions related to fragment shaders
		CHECK_EXTENSION(shader_objects);			// functions related to program and shaders
#undef CHECK_EXTENSION

		return {};
	}

	void GL3PlusRenderSystem::connectInputSystem(GL3PlusInputSystem* inputSystem, ToonResourceParser::INIParser const* inputInfo) noexcept
	{
		this->inputSystem = inputSystem;

		if (inputInfo)
		{
			// set input callbacks according to given input information ini file.
		}
		else
		{
			glfwSetKeyCallback(this->window, keyCallback);
			glfwSetCursorPosCallback(this->window, mousePosCallback);
			glfwSetMouseButtonCallback(this->window, mouseBtnCallback);
			glfwSetScrollCallback(this->window, scrollCallback);
			glfwSetFramebufferSizeCallback(this->window, resizingCallback);
			glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	}

	auto GL3PlusRenderSystem::getVendorString(void) const noexcept
	{
		return glGetString(GL_VENDOR);
	}
	auto GL3PlusRenderSystem::getRendererString(void) const noexcept
	{
		return glGetString(GL_RENDERER);
	}
	void GL3PlusRenderSystem::preDrawScene(void) const noexcept
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 0.0, 0.0, 1.0);
	}
	void GL3PlusRenderSystem::drawScene(void) const noexcept
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool GL3PlusRenderSystem::getWindowShouldClose(void) const noexcept
	{
		return glfwWindowShouldClose(window);
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_UNKNOWN || !GL3PlusInputSystem::isCorrectKey(key)) return;
		
		auto inputSystem = gInstance->inputSystem;
		auto& keyStorage = inputSystem->getKeyStorage();

		if (action == GLFW_PRESS) keyStorage[key] = true;
		else if (action == GLFW_RELEASE) keyStorage[key] = false;
	}
	void mousePosCallback(GLFWwindow* window, double xpos, double ypos)
	{

	}
	void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods)
	{

	}
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{

	}
	void resizingCallback(GLFWwindow* window, int newWidth, int newHeight)
	{

	}
#define GL3PLUS_KEY_CODE(key) (GLFW_KEY#key)
};