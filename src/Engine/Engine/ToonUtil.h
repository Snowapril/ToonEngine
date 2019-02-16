#ifndef TOON_UTIL_H
#define TOON_UTIL_H

#include "ToonHeaderPrefix.h"
#include <GL/glew.h>
#include <type_traits>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <typeinfo>
#include "Logger.h"

namespace Toon
{
	template < typename Type >
	void sendUniform( int program, char const* name, Type const & value )
	{
		int location = glGetUniformLocation( program, name );

		if (location == -1)
		{
			Logger::getConstInstance().errorMessage( "Undefined uniform name : {}", name );
			return;
		}
		
		if constexpr ( std::is_same_v< Type, glm::vec3 > )
			glUniform3fv( location, 1, &value.x );
		else if constexpr (std::is_same_v<Type, glm::vec4> )
			glUniform4fv( location, 1, &value.x );
		else if constexpr ( std::is_same_v<Type, glm::mat4> )
			glUniformMatrix4fv( location, 1, GL_FALSE, glm::value_ptr<glm::mat4>(value) );
		else
			Logger::getConstInstance().errorMessage( "Undefined uniform variable type : {}", typeid(Type).name() );
	}
}

#include "ToonHeaderPostfix.h"

#endif