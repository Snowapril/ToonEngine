#ifndef TOON_GL3_PLUS_RENDERSYSTEM_H
#define TOON_GL3_PLUS_RENDERSYSTEM_H

#include <string>
#include <optional>
#include <functional>

struct GLFWwindow;

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusRenderSystem class declaration
	****************************************************************************/
	class GL3PlusRendersystem
	{
	public:
		GL3PlusRendersystem() = default;
		GL3PlusRendersystem(char const* title, int width, int height, bool fullscreen = false) noexcept;
		GL3PlusRendersystem(GL3PlusRendersystem const&) = delete;
		GL3PlusRendersystem(GL3PlusRendersystem&&) = delete;
		GL3PlusRendersystem& operator=(GL3PlusRendersystem const&) = delete;
		GL3PlusRendersystem& operator=(GL3PlusRendersystem&&) = delete;

		virtual ~GL3PlusRendersystem() noexcept;

		GLFWwindow const* getWindow(void) const noexcept;
		double getAspectRatio(void) const noexcept; 

		// Opengl window and context initialization.
		// note : if this return {}, it means initialization was successful.
		std::optional<std::string> initWindow(std::string const & title, int width, int height, bool fullscreen = false) noexcept;

		void setCursorPosCallback(std::function<void(int, int)>) noexcept;
		void setWheelOffsetCallback(std::function<void(double, double)>) noexcept;
		void setKeyCallback(std::function<void(int, int, int, int)>) noexcept;
		void setResizeCallback(std::function<void(int, int)>) noexcept;

		auto getVendorString(void) const noexcept;
		auto getRendererString(void) const noexcept;
	public:
		void preDrawScene(void) const noexcept;		
		void drawScene(void) const noexcept;
	protected:
		std::string wndCaption{};
		GLFWwindow* window = nullptr;
		int clientWidth{ 0 };
		int clientHeight{ 0 };
		bool fullscreen{ false };
	};
};
#endif