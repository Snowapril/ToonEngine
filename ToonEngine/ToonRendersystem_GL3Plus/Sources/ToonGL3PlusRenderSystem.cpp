#include "stdafx.h"
#include "ToonGL3PlusRendersystem.h"
#include <glew/glew.h>
#include <GLFW/glfw3.h>

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include <fmt/format.h>

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusRenderSystem class definition
	****************************************************************************/

	GL3PlusRendersystem::GL3PlusRendersystem(char const* title, int width, int height, bool fullscreen) noexcept
	{
		assert(!initWindow(title, width, height, fullscreen));
	}
	GL3PlusRendersystem::~GL3PlusRendersystem() noexcept
	{
		glfwTerminate();
	}
	GLFWwindow const* GL3PlusRendersystem::getWindow(void) const noexcept
	{
		return window;
	}
	double GL3PlusRendersystem::getAspectRatio(void) const noexcept
	{
		return static_cast<double>(clientWidth) / clientHeight;
	}
	std::optional<std::string> GL3PlusRendersystem::initWindow(std::string const& title, int width, int height, bool fullscreen) noexcept
	{
		if (!glfwInit())	
		{
			glfwTerminate();
			return "GLFW initialization failed.";
		}

		this->wndCaption = title;
		this->clientWidth = width;
		this->clientHeight = height;
		this->fullscreen = fullscreen;

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

	auto GL3PlusRendersystem::getVendorString(void) const noexcept
	{
		return glGetString(GL_VENDOR);
	}
	auto GL3PlusRendersystem::getRendererString(void) const noexcept
	{
		return glGetString(GL_RENDERER);
	}
	void GL3PlusRendersystem::preDrawScene(void) const noexcept
	{
		glClearColor(1.0, 0.0, 0.0, 1.0);
	}
	void GL3PlusRendersystem::drawScene(void) const noexcept
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
};