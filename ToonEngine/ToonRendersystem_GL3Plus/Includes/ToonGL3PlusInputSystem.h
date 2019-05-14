/**
 * @file ToonGL3PlusInputSystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief Provide useful input system methods which controlled by OpenGL3 Callback system.
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_GL3_PLUS_INPUTSYSTEM_H
#define TOON_GL3_PLUS_INPUTSYSTEM_H

#include <string>
#include <unordered_map>
#include <vector>
#include <array>
#include <functional>
#include <ToonSingleton.h>

#include "ToonGL3PlusPlatform.h"

namespace ToonGL3Plus
{
	/****************************************************************************
				GL3Plus InputSystem class declaration here
	****************************************************************************/
	class GL3PlusInputSystem : public Common::Singleton<GL3PlusInputSystem>
	{
	public:
		using key_table_t		 = std::unordered_map<unsigned long, short>;
		using key_storage_t		 = std::array<bool, GL3PLUS_KEY_COUNT>;
		using callback_t		 = std::function<void()>;
		using callback_storage_t = std::array <std::vector<callback_t>, GL3PLUS_KEY_COUNT>;
	public:
		GL3PlusInputSystem() = default;
		virtual ~GL3PlusInputSystem() noexcept;
		
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
		inline bool isKeyPressed(short key) const noexcept
		{
			return isCorrectKey(key) ? keyStorage[key] : false;
		}
		
		inline constexpr static bool isCorrectKey(short key) noexcept
		{
			return 0 <= key && key < GL3PLUS_KEY_COUNT;
		}
	protected:
		key_storage_t keyStorage { false, };
		key_table_t keyTable { };
	};
};


#endif