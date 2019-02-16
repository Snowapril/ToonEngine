#ifndef GBUFFER_H
#define GBUFFER_H

#include "ToonHeaderPrefix.h"
#include "Framebuffer.h"

namespace Toon
{
	class GBuffer : public Framebuffer
	{
	public:
		GBuffer() = default;
		~GBuffer();

		virtual bool initFramebuffer(int width, int height, FRAMEBUFFER_FLAG flag) override;
		virtual void bindBuffer(void) const								   override;
	};
};

#include "ToonHeaderPostfix.h"

#endif