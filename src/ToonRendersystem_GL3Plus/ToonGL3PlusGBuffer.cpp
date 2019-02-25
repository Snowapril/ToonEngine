#include "stdafx.h"
#include "ToonGL3PlusGBuffer.h"
#include <GL/glew.h>

namespace ToonGL3Plus
{
	GBuffer::~GBuffer()
	{
	}

	bool GBuffer::initFramebuffer( int width, int height, FramebufferFlag flag )
	{
		bufferSize = glm::ivec2(width, height);
		return true;
	}

	void GBuffer::bindBuffer(void) const
	{
		Framebuffer::bindBuffer();

		for (int i = 0; i < colorTextures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture( GL_TEXTURE_2D, colorTextures[i] );
		}
	}
};