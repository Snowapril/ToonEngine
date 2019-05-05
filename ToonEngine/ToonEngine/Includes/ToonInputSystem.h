#ifndef TOON_INPUTSYSTEM_H
#define TOON_INPUTSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include "ToonString.h"
#include "ToonPlatform.h"

#include <ToonGL3PlusInputSystem.h>
#include <array>
#include <unordered_map>
#include <functional>
#include <vector>
#include <optional>

namespace Toon
{
	/****************************************************************************
						Inputsystem class declaration
	****************************************************************************/
	enum ToonKeyState
	{
		KEY_PRESSED		= 0,
		KEY_RELEASED	= 1,
		KEY_UNKNOWN		= 2,
		KEY_NUM_STATES	= KEY_UNKNOWN
	};
	
	class InputSystem : public ToonGL3Plus::GL3PlusInputSystem
	{
		using super_t = ToonGL3Plus::GL3PlusInputSystem;
	public:
		InputSystem() noexcept;
		~InputSystem() noexcept;

		void setKeyName(ToonString, short) noexcept;
		void addCallback(short, callback_t, ToonKeyState) noexcept;
		void addCallback(ToonString, callback_t, ToonKeyState) noexcept;

		ToonKeyState getKeyState(ToonString) const noexcept;
		ToonKeyState getKeyState(short) const noexcept;

		void envokeKey(ToonString, ToonKeyState) noexcept;
	private:
		std::optional<short> getKeyFromID(ToonString) const noexcept;
	private:
		std::array<callback_storage_t, KEY_NUM_STATES> callbackStorage{};
	};
};

#include "ToonHeaderPostfix.h"

#endif