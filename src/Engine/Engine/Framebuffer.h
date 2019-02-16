#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "ToonHeaderPrefix.h"
#include "NonCopyable.h"
#include <glm/vec2.hpp>
#include <vector>

namespace Toon
{
	enum class FRAMEBUFFER_FLAG : int
	{

	};

	class Framebuffer : public NonCopyable
	{
	protected:
		std::vector<unsigned int>		colorTextures;
		glm::ivec2						bufferSize;
		unsigned int					framebuffer  = 0U;
		unsigned int					depthTexture = 0U;
	public:
		Framebuffer() = default;
		virtual ~Framebuffer();

		virtual bool initFramebuffer( int width, int height, FRAMEBUFFER_FLAG flag );
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

#include "ToonHeaderPostfix.h"

#endif