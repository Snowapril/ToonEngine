#include "stdafx.h"
#include "ToonInputSystem.h"
#include "ToonLogger.h"
#include "ToonObfuscator.h"

namespace Toon
{
	enum class ToonKeyState : char
	{
		KEY_PRESSED  = 0,
		KEY_RELEASED = 1,
		KEY_UNKNOWN  = 2,
	};

	template <> InputSystem* Singleton<InputSystem>::instance = nullptr;

	InputSystem::~InputSystem()
	{

	}
	typename InputSystem::key_storage_t & InputSystem::getKeyStorage(void) noexcept
	{
		Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:<40} ({1:p})"), OBFUSCATE("Rendersystem instance is released"), reinterpret_cast<void*>(instance));
	}
	void InputSystem::addKey(ToonString const& keyMacro, char key) noexcept
	{
		auto hashKey = keyMacro.toHashKey();
		keyTable.insert(std::make_pair(hashKey, key));
	}
	ToonKeyState InputSystem::getKeyState(ToonString const& keyID) const noexcept
	{
		auto hashKey = keyID.toHashKey();
		auto iter = keyTable.find(hashKey);

		if (iter == end(keyTable)) return ToonKeyState::KEY_UNKNOWN;

		char key = iter->second;
		return keyStorage[key] ? ToonKeyState::KEY_PRESSED : ToonKeyState::KEY_RELEASED;
	}
	ToonKeyState InputSystem::getKeyState(char key) const noexcept
	{
		return ToonKeyState();
	}
};