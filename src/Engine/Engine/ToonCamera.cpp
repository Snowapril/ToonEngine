#include "stdafx.h"
#include "ToonCamera.h"

namespace Toon
{
	ToonCamera::ToonCamera()
	{
	}

	ToonCamera::ToonCamera(ToonCamera const &)
	{
	}

	ToonCamera::ToonCamera(ToonCamera &&)
	{
	}

	ToonCamera::~ToonCamera()
	{
	}

	ToonCamera & ToonCamera::operator=(ToonCamera const & other)
	{
		if ( &other != this )
		{

		}

		return *this;
	}

	ToonCamera & ToonCamera::operator=(ToonCamera && other)
	{
		if ( &other != this )
		{

		}

		return *this;
	}

	void ToonCamera::processInput( int key, int button )
	{
	}
};