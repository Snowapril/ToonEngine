/**
 * @file ToonInputSystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief input system for whole system. this class will inherit other input system which belong to the specific graphics system.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 */
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
	
	/**
	 * @brief inherit other input system which belong to the specific graphics system. In addition, more useful methods are added.
	 */
	class InputSystem : public ToonGL3Plus::GL3PlusInputSystem
	{
		using super_t = ToonGL3Plus::GL3PlusInputSystem;
	public:
		InputSystem() noexcept;
		~InputSystem() noexcept;

		/**
		 * @brief set the name of the given key code. 
		 * \code{.cpp}
		 * InputSystem is;
		 * is.setKeyName(ToonString("Attack"), 'a');
		 * \endcode
		 */
		void setKeyName(ToonString, short) noexcept;
		/**
		 * @brief set the callback on the specific key code.
		 * \code{.cpp}
		 * InputSystem is;
		 * is.addCallback('a', [](void){ //attack code }, KEY_PRESSED);
		 * \endcode
		 */
		void addCallback(short, callback_t, ToonKeyState) noexcept;
		/**
		 * @brief set the callback on the specific key code.
		 * \code{.cpp}
		 * InputSystem is;
		 * is.addCallback(ToonString("Attack"), [](void){ //attack code }, KEY_PRESSED);
		 * \endcode
		 */
		void addCallback(ToonString, callback_t, ToonKeyState) noexcept;

		/**
		 * @brief Get the Key State of given key name.
		 * 
		 * @return ToonKeyState 
		 */
		ToonKeyState getKeyState(ToonString) const noexcept;
		/**
		 * @brief Get the Key State of given key code.
		 * 
		 * @return ToonKeyState 
		 */
		ToonKeyState getKeyState(short) const noexcept;

		/**
		 * @brief set the key to specific state (which is equal to given second parameter).
		 * 
		 */
		void envokeKey(ToonString, ToonKeyState) noexcept;
	private:
		/**
		 * @brief return the key code of given name. if doesn't exists, return the optional failed.
		 * 
		 * @return std::optional<short> 
		 */
		std::optional<short> getKeyFromID(ToonString) const noexcept;
	private:
		std::array<callback_storage_t, KEY_NUM_STATES> callbackStorage{};
	};
};

#include "ToonHeaderPostfix.h"

#endif