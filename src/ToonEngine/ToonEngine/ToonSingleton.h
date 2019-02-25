#ifndef TOON_SINGLETON_H
#define TOON_SINGLETON_H

// referencing on Ogre engine

#include "ToonHeaderPrefix.h"
#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include "ToonExceptions.h"

namespace Toon
{
	template <typename Type>
	class ToonSingleton : public ToonNoncopyable
	{
	protected:
		static Type * instance;
	public:
		static Type const&	getConstInstance	(void);
		static Type&		getMutableInstance	(void);
		static bool			isDestroyed			(void) { return instance == nullptr; }
	public:
		ToonSingleton();
		~ToonSingleton();
	};

	template <typename Type>
	ToonSingleton< Type >::ToonSingleton()
	{
		ToonAssert( "The instance is already allocated", instance == nullptr );
		instance = static_cast<Type*>(this);
	}

	template <typename Type>
	ToonSingleton< Type >::~ToonSingleton()
	{
		assert(instance != nullptr);
		instance = nullptr;
	}

	template <typename Type>
	Type const&	ToonSingleton<Type>::getConstInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
	}

	template <typename Type>
	Type& ToonSingleton<Type>::getMutableInstance(void)
	{
		assert(instance != nullptr);
		return *instance;
	}
};

#include "ToonHeaderPostfix.h"

#endif //TOON_SINGLETON_HPP