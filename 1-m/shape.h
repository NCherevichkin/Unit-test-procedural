#ifndef SHAPE_H
#define SHAPE_H

#include "box.h"
#include "sphere.h"
#include "tetrahedron.h"

namespace simple_shapes 
{
	struct shape
	{
		enum key { BOX, SPHERE, TETRAHEDRON };
		key k;
		int temperature;
		union
		{
			box boxElement;
			sphere sphereElement;
			tetrahedron tetrahedronElement;
		};
	};
}
#endif