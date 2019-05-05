#ifndef TOON_EDITOR_ROOT_EDITOR_H
#define TOON_EDITOR_ROOT_EDITOR_H

#include <ToonRoot.h>

namespace ToonEditor
{
	/****************************************************************************
						ToonRoot class declaration
	****************************************************************************/
	class ToonEditorRoot : public Toon::ToonRoot
	{
		using super_t = Toon::ToonRoot;
	public:
		ToonEditorRoot();
		~ToonEditorRoot();
	public:
		int runMainLoop(void) noexcept;
	private:
		void drawToolbar(void) noexcept;
		void drawToolbox(void) noexcept;
		void drawPreview(void) noexcept;
		void drawFooter(void) noexcept;
		void drawMenubar(void) noexcept;
	};
};

#endif