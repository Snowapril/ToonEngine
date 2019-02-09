#ifndef UTIL_H
#define UTIL_H

#include <GL/glew.h>
#include <type_traits>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <typeinfo>
#include "Logger.h"

namespace snowapril
{
	template <typename Type>
	void sendUniform(int program, char const* name, const Type& value)
	{
		int location = glGetUniformLocation(program, name);

		if (location == -1)
		{
			ERROR_LOG("Undefined uniform name : {}", name);
			return;
		}
		
		if constexpr (std::is_same_v<Type, glm::vec3>)
			glUniform3fv(location, 1, &value.x);
		else if constexpr (std::is_same_v<Type, glm::vec4>)
			glUniform4fv(location, 1, &value.x);
		else if constexpr (std::is_same_v<Type, glm::mat4>)
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr<glm::mat4>(value));
		else
			ERROR_LOG("Undefined uniform variable type : {}", typeid(Type).name());
	}
}

#endif