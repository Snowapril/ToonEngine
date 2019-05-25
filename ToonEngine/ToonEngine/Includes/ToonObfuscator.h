/**
 * @file ToonObfuscator.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide obfuscating macro using template meta programming.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 */
#ifndef TOON_OBFUSCATOR_H
#define TOON_OBFUSCATOR_H

#include "ToonHeaderPrefix.h"
/*
reference : https://github.com/andrivet/ADVobfuscator
*/

/****************************************************************************
				String obfuscator functions here.
****************************************************************************/
namespace Toon
{
	template < int... I >
	struct Indexes { using type = Indexes<I..., sizeof...(I)>; };

	template < int N >
	struct MakeIndexes { using type = typename MakeIndexes<N - 1>::type::type; };

	template <>
	struct MakeIndexes<0> { using type = Indexes<>; };

	template < typename Indexes >
	class MetaString;

	template < int... I >
	class MetaString< Indexes<I...> >
	{
	public:
		constexpr MetaString( char const * str )
			: buffer{ encrypt(str[I])... } {};
	public:
		inline char const * decrypt(void)
		{
			for (size_t i = 0; i < sizeof...(I); ++i)
				buffer[i] = decrypt(buffer[i]);
			buffer[sizeof...(I)] = 0;
			return buffer;
		}
	private:
		constexpr char encrypt(char c) const { return c ^ 0x55; };
		constexpr char decrypt(char c) const { return encrypt(c); };
	private:
		char buffer[sizeof...(I) + 1];
	};

};

#define OBFUSCATE(str) ( Toon::MetaString<Toon::MakeIndexes< sizeof((str)) - 1 >::type>((str)).decrypt() )
#include "ToonHeaderPostfix.h"

#endif