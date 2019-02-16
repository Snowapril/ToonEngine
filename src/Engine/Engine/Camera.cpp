#include "stdafx.h"
#include "Camera.h"

namespace Toon
{
	Camera::Camera()
	{
	}

	Camera::Camera(Camera const &)
	{
	}

	Camera::Camera(Camera &&)
	{
	}

	Camera::~Camera()
	{
	}

	Camera & Camera::operator=(Camera const & other)
	{
		if ( &other != this )
		{

		}

		return *this;
	}

	Camera & Camera::operator=(Camera && other)
	{
		if ( &other != this )
		{

		}

		return *this;
	}

	void Camera::processInput( int key, int button )
	{
	}
};