#ifndef SINGLETON_H
#define SINGLETON_H

#include "NonCopyable.h"
#include <memory>

template <typename Type>
class Singleton : public NonCopyable 
{
private:
	static std::shared_ptr<Type> instance;
public:
	static Type const&	getConstInstance  (void) { return *instance;			}
	static Type&		getMutableInstance(void) { return *instance;			}
	static bool			isDestroyed		  (void) { return instance == nullptr;	}
	static void			destroyInstance	  (void) { instance.reset();			}
};

#endif //SINGLETON_HPP