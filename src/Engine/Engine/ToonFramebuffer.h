#ifndef TOON_FRAMEBUFFER_H
#define TOON_FRAMEBUFFER_H

#include "ToonHeaderPrefix.h"
#include "ToonNonCopyable.h"
#include <glm/vec2.hpp>
#include <vector>

namespace Toon
{
	enum class ToonFramebufferFlag : int
	{

	};

	class ToonFramebuffer : public ToonNoncopyable
	{
	protected:
		std::vector<unsigned int>		colorTextures;
		glm::ivec2						bufferSize;
		unsigned int					framebuffer  = 0U;
		unsigned int					depthTexture = 0U;
	public:
		ToonFramebuffer() = default;
		virtual ~ToonFramebuffer();

		virtual bool initFramebuffer( int width, int height, ToonFramebufferFlag flag );
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