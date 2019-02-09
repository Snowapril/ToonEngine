#include "GBuffer.h"
#include <GL/glew.h>

GBuffer::~GBuffer()
{
}

bool GBuffer::initFramebuffer(int width, int height, FRAMEBUFFER_FLAG flag)
{
	bufferSize = glm::ivec2(width, height);
	return true;
}

void GBuffer::bindBuffer(void) const
{
	Framebuffer::bindBuffer();
	
	for ( int i = 0; i < colorTextures.size(); i++ )
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, colorTextures[i]);
	}
}
