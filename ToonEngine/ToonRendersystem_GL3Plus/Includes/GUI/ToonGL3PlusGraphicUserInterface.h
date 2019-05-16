#ifndef TOON_GL3_PLUS_GRAPHIC_USER_INTERFACE_H
#define TOON_GL3_PLUS_GRAPHIC_USER_INTERFACE_H

#include <ToonNoncopyable.h>

namespace ToonGL3Plus
{
	class GL3PlusGraphicUserInterface : public Common::Noncopyable
	{
	public:
		GL3PlusGraphicUserInterface() = default;
		virtual ~GL3PlusGraphicUserInterface();
	private:
		bool initGUI(void) noexcept;
	};
};

#endif