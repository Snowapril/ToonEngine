#ifndef MESH_H
#define MESH_H

#include "Material.h"
#include "cgmath.h"
#include <vector>

class Mesh
{
private:
	std::vector<vec3>	  positions;
	std::vector<vec3>	  normals;
	std::vector<vec2>	  uvs;
	std::vector<uint32_t> indices;
public:
	Mesh() = default;
	Mesh(const Mesh&);
	Mesh& operator=(const Mesh&);
	Mesh(Mesh&&);
	Mesh& operator=(Mesh&&);

	std::size_t  getNumVertices (void) const;
	float const* getPositions   (void) const;
	float const* getNormals	    (void) const;
	float const* getUVs		    (void) const;
	std::size_t  getNumTriangles(void) const;

	bool hasPositions(void) const;
	bool hasNormals	 (void)	const;
	bool hasUVs		 (void)	const;
};

#endif