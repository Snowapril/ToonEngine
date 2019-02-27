#include "stdafx.h"
#include "ToonSystemMessageBus.h"
#include "ToonLogger.h"
#include "ToonSystemMessage.h"

namespace Toon
{
	template <> SystemMessageBus* Singleton< SystemMessageBus >::instance = nullptr;

	SystemMessageBus::SystemMessageBus() noexcept
	{

	}

	SystemMessageBus::~SystemMessageBus() noexcept
	{
		Logger::getConstInstance().infoMessage("[Singleton] SystemMessageBus instance is released ({0:x})", reinterpret_cast<void*>(instance) );
	}

	void SystemMessageBus::postSystemMessageImmediately(SystemMessage&& msg) noexcept
	{
		SystemMessage msg = std::move(msg);
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

	SystemMessageBus const&	SystemMessageBus::getConstInstance(void)
	{
		return *instance;
	}

	SystemMessageBus& SystemMessageBus::getMutableInstance(void)
	{
		return *instance;
	}
};