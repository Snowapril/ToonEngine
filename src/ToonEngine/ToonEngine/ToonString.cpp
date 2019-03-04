#include "stdafx.h"
#include "ToonString.h"

Toon::ToonString::ToonString(unsigned long key)
{
}

Toon::ToonString::ToonString(char const * str)
{
}

bool Toon::ToonString::operator==(ToonString const & other) const
{
	return false;
}

bool Toon::ToonString::operator==(char const * str) const
{
	return false;
}