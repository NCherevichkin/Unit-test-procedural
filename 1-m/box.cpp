#include <iostream>
#include <fstream>

#include "box.h"

using namespace std;

namespace simple_shapes
{
	void In(box &boxElement, ifstream &ifst)
	{
		try
		{
			ifst >> boxElement.x >> boxElement.y >> boxElement.z;
			if (boxElement.x <= 0 || boxElement.y <= 0 || boxElement.z <= 0)
				throw exception("Стороны параллелепипеда должны быть положительными! Работа программы прекращена.");
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	void Out(box &boxElement, ofstream &ofst)
	{
		ofst << "It is Box: x = " << boxElement.x << ", y = " << boxElement.y << ", z = " << boxElement.z << ", ";
	}

	double V(box &boxElement)
	{
		return boxElement.x * boxElement.y * boxElement.z;
	}
} 