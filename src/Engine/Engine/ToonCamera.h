#ifndef TOON_CAMERA_H
#define TOON_CAMERA_H

#include <glm/vec3.hpp>

namespace Toon
{
	class ToonCamera
	{
	private:
		glm::vec3	position;
		glm::vec3	direction;
		float		speed;
	public:
		ToonCamera();
		ToonCamera(ToonCamera const &);
		ToonCamera(ToonCamera&&);
		~ToonCamera();
		ToonCamera& operator=(ToonCamera const &);
		ToonCamera& operator=(ToonCamera&&);

		void processInput( int key, int button );
	};
};

#endif