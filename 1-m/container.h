#ifndef CONTAINER_H
#define CONTAINER_H

#include "shape.h"

namespace simple_shapes 
{
	struct container
	{
		int len; 
		shape* cont[100];
	};
}
#endif