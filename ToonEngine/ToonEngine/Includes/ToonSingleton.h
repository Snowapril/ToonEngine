#ifndef TOON_SINGLETON_H
#define TOON_SINGLETON_H

// referencing on Ogre engine

#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include <cassert>

namespace Toon
{
	/****************************************************************************
						Singleton class declaration
	****************************************************************************/
	template <typename Type>
	class Singleton : public Noncopyable
	{
	protected:
		static Type * instance;
	public:
		static Type const&	getConstInstance	(void);
		static Type&		getMutableInstance	(void);
		static bool			isDestroyed			(void) { return instance == nullptr; }
	public:
		Singleton();
		virtual ~Singleton();
	};

	/****************************************************************************
						Singleton class definition
	****************************************************************************/
	template <typename Type>
	Singleton< Type >::Singleton()
	{
		assert(instance == nullptr);
		instance = static_cast<Type*>(this);
	}

	template <typename Type>
	Singleton< Type >::~Singleton()
	{
		assert(instance != nullptr);
		instance = nullptr;
	}

	template <typename Type>
	Type const&	Singleton<Type>::getConstInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
	}

	template <typename Type>
	Type& Singleton<Type>::getMutableInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
	}
};

#include "ToonHeaderPostfix.h"

#endif //TOON_SINGLETON_HPP