#include "stdafx.h"
#include "ToonMesh.h"

namespace Toon
{
	ToonMesh::ToonMesh(ToonMesh const & other)
		: positions(other.positions), normals(other.normals), uvs(other.uvs), indices(other.indices)
	{
	}

	ToonMesh & ToonMesh::operator=(ToonMesh const & other)
	{
		if (this != &other)
		{
			positions	= other.positions;
			normals		= other.normals;
			uvs			= other.uvs;
			indices		= other.indices;
		}

		return *this;
	}

	ToonMesh::ToonMesh(ToonMesh&& other)
		: positions(move(other.positions)), normals(move(other.normals)), uvs(move(other.uvs)), indices(move(other.indices))
	{
	}

	ToonMesh & ToonMesh::operator=(ToonMesh&& other)
	{
		if (this != &other)
		{
			positions	= move(other.positions);
			normals		= move(other.normals);
			uvs			= move(other.uvs);
			indices		= move(other.indices);
		}

		return *this;
	}

	std::size_t ToonMesh::getNumVertices(void) const
	{
		return std::size_t();
	}

	float const* ToonMesh::getPositions(void) const
	{
		return hasPositions() ? &(positions[0].x) : nullptr;
	}

	float const* ToonMesh::getNormals(void) const
	{
		return hasNormals() ? &(normals[0].x) : nullptr;
	}

	float const* ToonMesh::getUVs(void) const
	{
		return hasUVs() ? &(uvs[0].x) : nullptr;
	}

	std::size_t ToonMesh::getNumTriangles(void) const
	{
		return static_cast<std::size_t>( indices.size() * 0.3333333f );
	}

	bool ToonMesh::hasPositions(void) const
	{
		return !positions.empty();
	}

	bool ToonMesh::hasNormals(void) const
	{
		return !normals.empty();
	}

	bool ToonMesh::hasUVs(void) const
	{
		return !uvs.empty();
	}
};