#include "stdafx.h"
#include "ToonFramebuffer.h"
#include <GL/glew.h>

namespace Toon
{
	ToonFramebuffer::~ToonFramebuffer()
	{
		if (!colorTextures.empty()) glDeleteTextures( static_cast<GLsizei>(colorTextures.size()), &colorTextures[0] );
		if (depthTexture != 0U)		glDeleteTextures( 1, &depthTexture );
		if (framebuffer != 0U)		glDeleteFramebuffers( 1, &framebuffer );
	}

	bool ToonFramebuffer::initFramebuffer( int width, int height, ToonFramebufferFlag flag )
	{
		bufferSize = glm::ivec2( width, height );


		return true;
	}

	void ToonFramebuffer::bindBuffer(void) const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		if (depthTexture == 0)	glClear( GL_COLOR_BUFFER_BIT						);
		else					glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT	);
	}

	void ToonFramebuffer::unbindBuffer(void) const
	{
		glBindFramebuffer( GL_FRAMEBUFFER, 0U );
	}
};

