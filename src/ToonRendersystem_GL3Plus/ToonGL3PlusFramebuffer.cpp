#include "stdafx.h"
#include "ToonGL3PlusFramebuffer.h"
#include <GL/glew.h>

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusFramebuffer class definition
	****************************************************************************/
	GL3PlusFramebuffer::~GL3PlusFramebuffer()
	{
		if (!colorTextures.empty()) glDeleteTextures( static_cast<GLsizei>(colorTextures.size()), &colorTextures[0] );
		if (depthTexture != 0U)		glDeleteTextures( 1, &depthTexture );
		if (framebuffer != 0U)		glDeleteFramebuffers( 1, &framebuffer );
	}

	bool GL3PlusFramebuffer::initFramebuffer( int width, int height, FramebufferFlag flag )
	{
		bufferSize = glm::ivec2( width, height );


		return true;
	}

	void GL3PlusFramebuffer::bindBuffer(void) const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		if (depthTexture == 0)	glClear( GL_COLOR_BUFFER_BIT						);
		else					glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT	);
	}

	void GL3PlusFramebuffer::unbindBuffer(void) const
	{
		glBindFramebuffer( GL_FRAMEBUFFER, 0U );
	}
};

