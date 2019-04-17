#ifndef TOON_INPUTSYSTEM_H
#define TOON_INPUTSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include "ToonSingleton.h"		
#include "ToonString.h"
#include "ToonPlatform.h"

#include <ToonGL3PlusInputSystem.h>

#include <array>
#include <unordered_map>
#include <functional>
#include <vector>
#include <optional>

struct GLFWwindow;

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

		using callback_t		 = std::function<void()>;
		using callback_storage_t = std::array <std::vector<callback_t>, GL3PLUS_KEY_COUNT>;
	private:
		static InputSystem* instance;
	public:
		InputSystem() noexcept;
		~InputSystem();
	public:
		static InputSystem const& getConstInstance(void);
		static InputSystem& getMutableInstance(void);
		static bool isDestroyed(void) { return instance == nullptr; }

		void setKeyName(ToonString, char) noexcept;
		void addCallback(char, callback_t, ToonKeyState) noexcept;
		void addCallback(ToonString, callback_t, ToonKeyState) noexcept;

		ToonKeyState getKeyState(ToonString) const noexcept;
		ToonKeyState getKeyState(char) const noexcept;

		void envokeKey(ToonString, ToonKeyState) noexcept;
	private:
		std::optional<char> getKeyFromID(ToonString) const noexcept;
	private:
		std::array<callback_storage_t, KEY_NUM_STATES> callbackStorage{};
	};
};

#include "ToonHeaderPostfix.h"

#endif