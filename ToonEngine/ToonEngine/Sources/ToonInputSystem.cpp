#include "stdafx.h"
#include "ToonInputSystem.h"
#include "ToonLogger.h"
#include "ToonObfuscator.h"

namespace Common
{
	template <> Toon::InputSystem* Singleton<Toon::InputSystem>::instance = nullptr;
}

namespace Toon
{
	InputSystem::InputSystem() noexcept
		: super_t()
	{
	}
	InputSystem::~InputSystem() noexcept
	{
		Logger::getConstInstance().infoMessage(OBFUSCATE("[Singleton] {0:>40} ({1:p})"), OBFUSCATE("Rendersystem instance is released"), reinterpret_cast<void*>(instance));
	}
	void InputSystem::setKeyName(ToonString keyMacro, short key) noexcept
	{
		if (super_t::isCorrectKey(key))
		{
			auto hashKey = keyMacro.toHashKey();
			keyTable.insert(std::make_pair(hashKey, key));
		}
	}
	void InputSystem::addCallback(short key, callback_t callback, ToonKeyState keyState) noexcept
	{
		if (super_t::isCorrectKey(key))
		{
			callback_storage_t& storageArray = callbackStorage[keyState];
			storageArray[key].push_back(callback);
		}
	}
	void InputSystem::addCallback(ToonString keyID, callback_t callback, ToonKeyState keyState) noexcept
	{
		auto keyOption = getKeyFromID(keyID);
		if (keyOption.has_value())
		{
			callback_storage_t& storageArray = callbackStorage[keyState];
			storageArray[ keyOption.value() ].push_back(callback);
		}
	}
	ToonKeyState InputSystem::getKeyState(ToonString keyID) const noexcept
	{
		auto keyOption = getKeyFromID(keyID);
		if (keyOption.has_value()) return ToonKeyState::KEY_UNKNOWN;

		short key = keyOption.value();
		return keyStorage[key] ? ToonKeyState::KEY_PRESSED : ToonKeyState::KEY_RELEASED;
	}
	ToonKeyState InputSystem::getKeyState(short key) const noexcept
	{
		if (super_t::isCorrectKey(key))		return ToonKeyState::KEY_UNKNOWN; // when unknown key is given (is not in range of ASCII Code)
		else								return keyStorage[key] ? ToonKeyState::KEY_PRESSED : ToonKeyState::KEY_RELEASED; 
	}
	
	void InputSystem::envokeKey(ToonString keyID, ToonKeyState keyState) noexcept
	{
		auto keyOption = getKeyFromID(keyID);

		if (keyOption.has_value())
		{
			short key = keyOption.value();
			callback_storage_t& storageOnPress = callbackStorage[keyState];
			for (auto callback : storageOnPress[key])
			{
				callback();
			}
		}
	}
	std::optional<short> InputSystem::getKeyFromID(ToonString keyID) const noexcept
	{
		auto hashKey = keyID.toHashKey();
		auto iter = keyTable.find(hashKey);

		if (iter == end(keyTable))	return {};
		else						return iter->second;
	}
};