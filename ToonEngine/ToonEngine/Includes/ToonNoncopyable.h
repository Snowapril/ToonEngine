#ifndef TOON_NONCOPYABLE_H
#define TOON_NONCOPYABLE_H

#include "ToonHeaderPrefix.h"

namespace Toon
{
	/****************************************************************************
							Noncopyable class declaration
	****************************************************************************/
	class Noncopyable
	{
	public:
		Noncopyable() = default;
		Noncopyable(Noncopyable const&) = delete;
		Noncopyable(Noncopyable&&	  ) = delete;
		Noncopyable& operator=(Noncopyable const&) = delete;
		Noncopyable& operator=(Noncopyable&&	 ) = delete;

		virtual ~Noncopyable() = 0 {};
	};
};

#include "ToonHeaderPostfix.h"

#endif //TOON_NONCOPYABLE_H