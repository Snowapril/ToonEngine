#include "stdafx.h"
#include "ToonGL3PlusFramebuffer.h"
#include <GL/glew.h>

namespace ToonGL3Plus
{
	Framebuffer::~Framebuffer()
	{
		if (!colorTextures.empty()) glDeleteTextures( static_cast<GLsizei>(colorTextures.size()), &colorTextures[0] );
		if (depthTexture != 0U)		glDeleteTextures( 1, &depthTexture );
		if (framebuffer != 0U)		glDeleteFramebuffers( 1, &framebuffer );
	}

	bool Framebuffer::initFramebuffer( int width, int height, FramebufferFlag flag )
	{
		bufferSize = glm::ivec2( width, height );


		return true;
	}

	void Framebuffer::bindBuffer(void) const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		if (depthTexture == 0)	glClear( GL_COLOR_BUFFER_BIT						);
		else					glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT	);
	}

	void Framebuffer::unbindBuffer(void) const
	{
		glBindFramebuffer( GL_FRAMEBUFFER, 0U );
	}
};

