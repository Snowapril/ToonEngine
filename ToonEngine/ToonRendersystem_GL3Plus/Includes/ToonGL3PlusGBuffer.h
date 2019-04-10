#ifndef TOON_GBUFFER_H
#define TOON_GBUFFER_H

#include <ToonHeaderPrefix.h>
#include "ToonGL3PlusFramebuffer.h"

namespace ToonGL3Plus
{
	/****************************************************************************
						GL3PlusGBuffer class declaration
	****************************************************************************/
	class GL3PlusGBuffer : public GL3PlusFramebuffer
	{
	public:
		GL3PlusGBuffer() = default;
		~GL3PlusGBuffer();

		virtual bool initFramebuffer(int width, int height, FramebufferFlag flag) override;
		virtual void bindBuffer(void) const	override;
	};
};

#include <ToonHeaderPostfix.h>

#endif