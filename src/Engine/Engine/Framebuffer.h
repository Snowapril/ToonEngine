#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "NonCopyable.h"
#include <stdint.h>
#include <glm/vec2.hpp>
#include <vector>

enum class FRAMEBUFFER_FLAG : int
{

};

class Framebuffer : public NonCopyable
{
protected:
	std::vector<uint32_t>	colorTextures;
	glm::ivec2				bufferSize;
	uint32_t				framebuffer  = 0U;
	uint32_t				depthTexture = 0U;
public:
	Framebuffer() = default;
	virtual ~Framebuffer();

	virtual bool initFramebuffer(int width, int height, FRAMEBUFFER_FLAG flag);
	virtual void bindBuffer(void) const;
	void unbindBuffer	   (void) const;

	int getColorTexture(int index) const
	{
		return colorTextures[index];
	}
	int getDepthTexture(void) const
	{
		return depthTexture;
	}
	ivec2    getBufferSize  (void) const
	{
		return bufferSize;
	}
};

#endif