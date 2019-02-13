#ifndef SINGLETON_H
#define SINGLETON_H

#include "NonCopyable.h"

template <typename Type>
class Singleton : public NonCopyable 
{
private:
	static Type *instance = nullptr;
public:
	static Type const&	getConstInstance  (void);
	static Type&		getMutableInstance(void);
	static bool			isDestroyed		  (void) { return instance == nullptr;			}
	static void			destroyInstance(void)	 { delete instance; instance = nullptr; }
private: 
	// to prevent the constructor of singleton from being called from any place.
	Singleton() = default; 
};

template <typename Type>
Type const&	Singleton<Type>::getConstInstance(void)
{
	if (instance == nullptr)
		instance = new Type();

	return instance;
}

template <typename Type>
Type& Singleton<Type>::getMutableInstance(void)
{
	if (instance == nullptr)
		instance = new Type();

	return instance;
}

#endif //SINGLETON_HPP