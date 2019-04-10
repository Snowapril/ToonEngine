#ifndef TOON_GL3_PLUS_RENDERSYSTEM_H
#define TOON_GL3_PLUS_RENDERSYSTEM_H

#include <string>
#include <optional>
#include <ToonEngineSystem.h>

struct GLFWwindow;

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusRenderSystem class declaration
	****************************************************************************/
	class GL3PlusRendersystem : public Toon::EngineSystem
	{
	public:
		GL3PlusRendersystem() = default;
		GL3PlusRendersystem(char const* title, int width, int height) noexcept;
		virtual ~GL3PlusRendersystem() noexcept;

		GLFWwindow const* getWindow(void) const noexcept;
		double getAspectRatio(void) const noexcept; 

		std::optional<std::string> initWindow(char const* title, int width, int height) noexcept;

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