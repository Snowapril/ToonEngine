#ifndef TOON_GL3_PLUS_RENDERSYSTEM_H
#define TOON_GL3_PLUS_RENDERSYSTEM_H

#include <optional>
#include <functional>
#include <ToonSingleton.h>
#include <INIParser.h>

#include "ToonGL3PlusPrerequisites.h"

struct GLFWwindow;

namespace ToonGL3Plus
{
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
	void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods);
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	void resizingCallback(GLFWwindow* window, int newWidth, int newHeight);
	/****************************************************************************
						GL3PlusRenderSystem class declaration
	****************************************************************************/
	class GL3PlusRenderSystem : public Common::Singleton<GL3PlusRenderSystem>
	{
		friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
		friend void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
		friend void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods);
		friend void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		friend void resizingCallback(GLFWwindow* window, int newWidth, int newHeight);
	public:
		GL3PlusRenderSystem();
		GL3PlusRenderSystem(std::string const &title, int width, int height, bool fullscreen = false) noexcept;

		virtual ~GL3PlusRenderSystem() noexcept;

		GLFWwindow const* getWindow(void) const noexcept;
		double getAspectRatio(void) const noexcept; 

		// Opengl window and context initialization.
		// note : if this return {}, it means initialization was successful.
		std::optional<std::string> initWindow(std::string const &title, int width, int height, bool fullscreen = false) noexcept;
		void connectInputSystem(GL3PlusInputSystem* inputSystem, ToonResourceParser::INIParser const * inputInfo = nullptr) noexcept;

		auto getVendorString(void) const noexcept;
		auto getRendererString(void) const noexcept;
	public:
		void preDrawScene(void) const noexcept;		
		void drawScene(void) const noexcept;
		bool getWindowShouldClose(void) const noexcept;
	protected:
		std::string wndCaption {};
		
		GL3PlusInputSystem* inputSystem = nullptr; // must be manually deallocated at engine system.
		GLFWwindow* window = nullptr;

		int clientWidth { 0 };
		int clientHeight { 0 };
		bool fullscreen { false };
	};
};
#endif