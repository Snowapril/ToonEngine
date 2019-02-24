#include "stdafx.h"
#include "ToonGBuffer.h"
#include <GL/glew.h>

namespace Toon
{
	ToonGBuffer::~ToonGBuffer()
	{
	}

	bool ToonGBuffer::initFramebuffer( int width, int height, ToonFramebufferFlag flag )
	{
		bufferSize = glm::ivec2(width, height);
		return true;
	}

	void ToonGBuffer::bindBuffer(void) const
	{
		ToonFramebuffer::bindBuffer();

		for (int i = 0; i < colorTextures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture( GL_TEXTURE_2D, colorTextures[i] );
		}
	}
};