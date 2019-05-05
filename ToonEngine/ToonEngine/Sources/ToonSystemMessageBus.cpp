#include "stdafx.h"
#include "ToonSystemMessageBus.h"
#include "ToonLogger.h"
#include "ToonObfuscator.h"

namespace Common
{
	template <> Toon::SystemMessageBus* Singleton<Toon::SystemMessageBus>::instance = nullptr;
}

namespace Toon
{
	/****************************************************************************
						SystemMessageBus class definition
	****************************************************************************/

	SystemMessageBus::SystemMessageBus() noexcept
	{

	}

	SystemMessageBus::~SystemMessageBus() noexcept
	{
		Logger::getConstInstance().infoMessage( OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("SystemMessageBus instance is released"), reinterpret_cast<void*>(instance) );
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