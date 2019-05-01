#ifndef TOON_GL3_PLUS_INPUTSYSTEM_H
#define TOON_GL3_PLUS_INPUTSYSTEM_H

#include <string>
#include <unordered_map>
#include <vector>
#include <array>

#include "ToonGL3PlusPlugin.h"
#include "ToonGL3PlusPlatform.h"

namespace ToonGL3Plus
{
	/****************************************************************************
				GL3Plus InputSystem class declaration here
	****************************************************************************/
	class _ToonExport GL3PlusInputSystem
	{
		using key_table_t		 = std::unordered_map<unsigned long, char>;
		using key_storage_t		 = std::array<bool, GL3PLUS_KEY_COUNT>;
	public:
		GL3PlusInputSystem() = default;
		
		// be cautious of this method, because it return reference of member variable.
		// trade off for fast accessing to key inputs.
		inline key_storage_t& getKeyStorage(void) noexcept 
		{
			return keyStorage;
		}
		// be cautious of this method, because it return reference of member variable.
		// trade off for fast accessing to key inputs.
		inline key_storage_t const& getKeyStorage(void) const noexcept
		{
			return keyStorage;
		}
		// if given key has correct key value, return whether it's key pressed or not.
		// otherwise, always return false.
		inline bool isKeyPressed(char key) const noexcept
		{
			return isCorrectKey(key) ? keyStorage[key] : false;
		}
		
		inline constexpr static bool isCorrectKey(char key) noexcept
		{
			return 0 <= key && key < 104;
		}
	protected:
		key_storage_t keyStorage { false, };
		key_table_t keyTable { };
	};
};


#endif