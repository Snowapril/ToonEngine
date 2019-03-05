#ifndef TOON_SYSTEM_MESSAGE_BUS_H
#define TOON_SYSTEM_MESSAGE_BUS_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include "ToonPrerequisites.h"
#include <functional>
#include <queue>
#include <vector>
#include "ToonSystemMessage.h"

namespace Toon
{
	/****************************************************************************
						SystemMessageBus class declaration
	****************************************************************************/
	class SystemMessageBus : public Singleton<SystemMessageBus>
	{
	private:
		std::queue<SystemMessage> msgQueue;
		std::vector< SystemMessageListener > listeners;
	public:
		SystemMessageBus() noexcept;
		~SystemMessageBus() noexcept;

		void postSystemMessageImmediately	(SystemMessage&&  )	noexcept;
		void postSystemMessage				(SystemMessage&&  )	noexcept;
		void addSystemMessageListener		(SystemMessageListener) noexcept;
		void notifySystemMessage			(void)					noexcept;
	public:
		static SystemMessageBus const&	getConstInstance	(void);
		static SystemMessageBus &		getMutableInstance	(void);
		static bool							isDestroyed			(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif