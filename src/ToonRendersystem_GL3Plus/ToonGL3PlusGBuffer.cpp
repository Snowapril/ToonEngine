#include "stdafx.h"
#include "ToonGL3PlusGBuffer.h"
#include <GL/glew.h>

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusGBuffer class declaration
	****************************************************************************/
	GL3PlusGBuffer::~GL3PlusGBuffer()
	{
	}

	bool GL3PlusGBuffer::initFramebuffer( int width, int height, FramebufferFlag flag )
	{
		bufferSize = glm::ivec2(width, height);
		return true;
	}

	void GL3PlusGBuffer::bindBuffer(void) const
	{
		GL3PlusFramebuffer::bindBuffer();

		for (int i = 0; i < colorTextures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture( GL_TEXTURE_2D, colorTextures[i] );
		}
	}
};