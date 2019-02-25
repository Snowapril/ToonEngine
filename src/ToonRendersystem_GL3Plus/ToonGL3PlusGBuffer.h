#ifndef TOON_GBUFFER_H
#define TOON_GBUFFER_H

#include <ToonEngine/ToonHeaderPrefix.h>
#include "ToonGL3PlusFramebuffer.h"

namespace ToonGL3Plus
{
	class GBuffer : public Framebuffer
	{
	public:
		GBuffer() = default;
		~GBuffer();

		virtual bool initFramebuffer(int width, int height, FramebufferFlag flag) override;
		virtual void bindBuffer(void) const								   override;
	};
};

#include <ToonEngine/ToonHeaderPostfix.h>

#endif