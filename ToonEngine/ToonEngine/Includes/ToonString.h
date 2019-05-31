/**
 * @file ToonString.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief the string class of the toon engine. 
 * 
 * because comparing whole characters in the manual string will be highly computative, hashing the string into the integer value in advance.
 * comparing the two integer values will be absolutely more time-efficient than comparing the whole characters
 * 
 * \code{.cpp}
 * auto str = TOON_STRING("sinjihng");
 * std::cout << str.toString() << std::endl;
 * std::cout << std::hex << str.toHashKey() << std::endl;
 * auto str2 = TOON_STRING("dpgxgo");
 * 
 * if (str == str2) std::cout << "Same Strings" 	 << std::endl;
 * else 			std::cout << "Different Strings" << std::endl;
 * \endcode
 * 
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_STRING_H
#define TOON_STRING_H

#include <unordered_map>
#include "ToonPlatform.h"
#include "ToonCRC32Hash.h"

namespace Toon
{
	/****************************************************************************
						ToonString class declaration
	****************************************************************************/

	/**
	 * @brief string class of the toon engine.
	 * 
	 */
	class ToonString
	{
	private:
		static std::unordered_map<unsigned long, char const*> stringTable;
		unsigned long hashKey;
	public:
		/**
		 * @brief Construct empty ToonString.
		 * 
		 */
		ToonString();
		/**
		 * @brief construct ToonString with original string and hashed integer value. 
		 *
		 * original string and hash value will be automatically added on unordered_map.
		 * hashed value will be used for comparing and identifying. 
		 * original string will be used for rendering and printing.
		 * 
		 * @param buf - original string value.
		 * @param key - hashed integer value of original string.
		 */
		ToonString(char const * buf, unsigned long key);
		/**
		 * @brief compare the given string with the own string. 
		 * In case the string can not be hashed in compile time, comparing whole characters will be conducted instead of comparing the hashed values.
		 * 
		 * @param str 
		 * @return true 
		 * @return false 
		 */
		bool operator==(char const * str) const noexcept;
		/**
		 * @brief In case programmer stored the hashed integer value in integer variable, not ToonString instance, this operator overloading will be conducted.
		 * 
		 * @param key 
		 * @return TOON_FORCE_INLINE operator== 
		 */
		TOON_FORCE_INLINE bool operator==(unsigned long key) const noexcept
		{
			return hashKey == key;
		}
		/**
		 * @brief Compare the two ToonString instances. 
		 * Comparing the two ToonString instances is as same as comparing the two hashed integer values. Just one comparing will be occurred.
		 * 
		 * @param other 
		 * @return TOON_FORCE_INLINE operator== 
		 */
		TOON_FORCE_INLINE bool operator==(ToonString const & other) const noexcept
		{
			return hashKey == other.hashKey;
		} 
		/**
		 * @brief Get original string from the ToonString instance.
		 * 
		 * @return TOON_FORCE_INLINE const* toString 
		 */
		TOON_FORCE_INLINE char const* toString(void) const
		{
			return stringTable[hashKey];
		}
		/**
		 * @brief Get the hash value of the original string from the ToonString instance.
		 * 
		 * @return TOON_FORCE_INLINE toHashKey 
		 */
		TOON_FORCE_INLINE unsigned long toHashKey(void) const noexcept
		{
			return hashKey;
		}
	};
};

/**
 * @brief Shortened version of ToonString Constructor.
 * 
 * \code{.cpp}
 * auto str = TOON_STRING("sinjihng");
 * std::cout << str.toString() << std::endl;
 * std::cout << std::hex << str.toHashKey() << std::endl;
 * auto str2 = TOON_STRING("dpgxgo");
 * 
 * if (str == str2) std::cout << "Same Strings" 	 << std::endl;
 * else 			std::cout << "Different Strings" << std::endl;
 * \endcode
 * 
 */
#define TOON_STRING(str) (Toon::ToonString((str), CRC32_STRING_HASH((str))))

#endif // end of TOON_STRING_H