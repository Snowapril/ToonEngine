#pragma once

#include <glew/glew.h>
#include <type_traits>
#include <optional>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ToonGL3PlusErrorCodes.h"


namespace ToonGL3Plus
{

	template < typename Type >
	std::optional<std::string> sendUniform( int program, char const* name, Type && value ) noexcept
	{
		std::optional<std::string> option {};
		Type v		 = std::forward<Type>(value);
		int location = glGetUniformLocation(program, name);

		if (location == -1)
			option = getErrorString(RenderSystemErrorCodes::UNKNOWN_UNIFORM_VARIABLE_NAME);
		
		if constexpr ( std::is_same_v< Type, glm::vec3 > )
			glUniform3fv( location, 1, &v.x );
		else if constexpr (std::is_same_v<Type, glm::vec4> )
			glUniform4fv( location, 1, &v.x );
		else if constexpr ( std::is_same_v<Type, glm::mat4> )
			glUniformMatrix4fv( location, 1, GL_FALSE, glm::value_ptr<glm::mat4>(v) );
		else
			option = getErrorString(RenderSystemErrorCodes::UNKNOWN_UNIFORM_VARIABLE_NAME);

		return option;
	}
};
