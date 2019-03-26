#ifndef TOON_ENGINE_SYSTEM_H
#define TOON_ENGINE_SYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include "ToonPrerequisites.h"

namespace Toon
{
	/****************************************************************************
				EngineSystem class declaration
	****************************************************************************/
	class EngineSystem : public Noncopyable
	{
	public:
		virtual void handleSystemMessage(SystemMessage const & msg) = 0;
	};
};
#include "ToonHeaderPostfix.h"

#endif