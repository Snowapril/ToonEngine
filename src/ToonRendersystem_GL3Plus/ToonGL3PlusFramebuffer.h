#ifndef TOON_FRAMEBUFFER_H
#define TOON_FRAMEBUFFER_H

#include <ToonEngine/ToonHeaderPrefix.h>
#include <ToonEngine/ToonNonCopyable.h>
#include <glm/vec2.hpp>
#include <vector>

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusFramebuffer class declaration
	****************************************************************************/
	enum class FramebufferFlag : int
	{

	};

	class GL3PlusFramebuffer : public Toon::Noncopyable
	{
	protected:
		std::vector<unsigned int>		colorTextures;
		glm::ivec2						bufferSize;
		unsigned int					framebuffer  = 0U;
		unsigned int					depthTexture = 0U;
	public:
		GL3PlusFramebuffer() = default;
		virtual ~GL3PlusFramebuffer();

		virtual bool initFramebuffer( int width, int height, FramebufferFlag flag );
		virtual void bindBuffer(void) const;
		void unbindBuffer(void) const;

		int getColorTexture(int index) const
		{
			return colorTextures[index];
		}
		int getDepthTexture(void) const
		{
			return depthTexture;
		}
		glm::ivec2 getBufferSize(void) const
		{
			return bufferSize;
		}
	};
};

#include <ToonEngine/ToonHeaderPostfix.h>

#endif