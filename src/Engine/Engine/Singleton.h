#ifndef SINGLETON_H
#define SINGLETON_H

// referencing on Ogre engine

#include "ToonHeaderPrefix.h"
#include "ToonHeaderPrefix.h"
#include "NonCopyable.h"
#include "ToonExceptions.h"

namespace Toon
{
	template <typename Type>
	class Singleton : public NonCopyable
	{
	protected:
		static Type * instance;
	public:
		static Type const&	getConstInstance	(void);
		static Type&		getMutableInstance	(void);
		static bool			isDestroyed			(void) { return instance == nullptr; }
	public:
		Singleton();
		~Singleton();
	};

	template <typename Type>
	Singleton< Type >::Singleton()
	{
		ToonAssert( "The instance is already allocated", instance == nullptr );
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

#endif //SINGLETON_HPP