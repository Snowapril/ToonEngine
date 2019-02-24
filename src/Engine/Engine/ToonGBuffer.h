#ifndef TOON_GBUFFER_H
#define TOON_GBUFFER_H

#include "ToonHeaderPrefix.h"
#include "ToonFramebuffer.h"

namespace Toon
{
	class ToonGBuffer : public ToonFramebuffer
	{
	public:
		ToonGBuffer() = default;
		~ToonGBuffer();

		virtual bool initFramebuffer(int width, int height, ToonFramebufferFlag flag) override;
		virtual void bindBuffer(void) const								   override;
	};
};

#include "ToonHeaderPostfix.h"

#endif