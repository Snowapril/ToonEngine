#ifndef GBUFFER_H
#define GBUFFER_H

#include "Framebuffer.h"

class GBuffer : public Framebuffer
{
public:
	GBuffer() = default;
	~GBuffer();

	virtual bool initFramebuffer(int width, int height, FRAMEBUFFER_FLAG flag) override;
	virtual void bindBuffer		(void) const								   override;
};

#endif