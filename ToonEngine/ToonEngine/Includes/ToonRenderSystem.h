/**
 * @file ToonRenderSystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief toon engien render system which inherit other specific render system such as opengl, vulkan and directx. at now, inherits opengl render system.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include <ToonGL3PlusRendersystem.h>
#include <string>
#include <INIParser.h>

struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						RenderSystem class declaration
	****************************************************************************/

	/**
	 * @brief render system class for toon engine. this class inherits opengl render system.
	 * 
	 */
	class RenderSystem : public ToonGL3Plus::GL3PlusRenderSystem
	{
		using super_t = ToonGL3Plus::GL3PlusRenderSystem;
	public:
		RenderSystem() noexcept;
		~RenderSystem() noexcept;
	public:
		void preDrawScene(void) const noexcept;
		void drawScene	 (void) const noexcept;

		/**
		 * @brief initialize render system with given ini config file.
		 * 
		 * @return true  if initialization was successful, return true.
		 * @return false if initialization was failed, return false . (because of given ini file path does not eixsts, config file variables are wrong. etc...)
		 */
		bool initWindow	(ToonResourceParser::INIParser const&) noexcept;
	};
};

#include "ToonHeaderPostfix.h"

#endif