#ifndef TOON_INPUTSYSTEM_H
#define TOON_INPUTSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include "ToonSingleton.h"		
#include "ToonString.h"
#include "ToonPlatform.h"

#include <array>
#include <unordered_map>
#include <functional>

struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						Inputsystem class declaration
	****************************************************************************/

	enum class ToonKeyState : char;

	class InputSystem : public Singleton<InputSystem>
	{
		using key_storage_t = std::array<bool, TOON_KEY_COUNT>;
		using key_table_t	= std::unordered_map<unsigned long, char>;
		using callback_t	= std::function<void()>;
	public:
		~InputSystem();

		// be cautious of this method, because it return reference of member variable.
		// trade off for fast accessing to key inputs.
		key_storage_t& getKeyStorage(void) noexcept; 

		void addKey(ToonString const&, char) noexcept;
		void addCallback(char, callback_t) noexcept;
		void addCallback(ToonString const&, callback_t) noexcept;

		ToonKeyState getKeyState(ToonString const&) const noexcept;
		ToonKeyState getKeyState(char) const noexcept;
	private:
		key_storage_t keyStorage{ false, };
		key_table_t keyTable{};
	};
};

#include "ToonHeaderPostfix.h"

#endif