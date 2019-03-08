#include "stdafx.h"
#include "ToonSystemMessageBus.h"
#include "ToonLogger.h"

namespace Toon
{
	/****************************************************************************
						SystemMessageBus class definition
	****************************************************************************/
	template <> SystemMessageBus* Singleton< SystemMessageBus >::instance = nullptr;

	SystemMessageBus::SystemMessageBus() noexcept
	{

	}

	SystemMessageBus::~SystemMessageBus() noexcept
	{
		Logger::getConstInstance().infoMessage( OBFUSCATE("[Singleton] SystemMessageBus instance is released ({0:x})"), reinterpret_cast<void*>(instance) );
	}

	void SystemMessageBus::postSystemMessageImmediately(SystemMessage&& msg_) noexcept
	{
		SystemMessage msg = std::move(msg_);
		for (auto& listener : listeners)
			listener(msg);
	}

	void SystemMessageBus::postSystemMessage(SystemMessage&& msg) noexcept
	{
		msgQueue.push(std::move(msg));
	}

	void SystemMessageBus::addSystemMessageListener(SystemMessageListener listener) noexcept
	{
		listeners.push_back(listener);
	}

	void SystemMessageBus::notifySystemMessage(void) noexcept
	{
		while (!msgQueue.empty())
		{
			SystemMessage msg = std::move(msgQueue.front());
			msgQueue.pop();

			for (auto& listener : listeners)
			{
				listener(msg);
			}
		}
	}
};