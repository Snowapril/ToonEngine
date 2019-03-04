#ifndef TOON_ROOT_EDITOR_H
#define TOON_ROOT_EDITOR_H

#include <ToonEngine/ToonHeaderPrefix.h>
#include <ToonEngine/ToonRoot.h>

namespace ToonEditor
{
	/****************************************************************************
						ToonRoot class declaration
	****************************************************************************/
	class ToonRoot : public Toon::ToonRoot
	{
	private:
	public:
	public:
	private:
		void drawToolbar(void);
		void drawToolbox(void);
		void drawPreview(void);
	};
};

#include <ToonEngine/ToonHeaderPostfix.h>

#endif