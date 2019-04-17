#include <iostream>
#include <fstream>

#include "sphere.h"

using namespace std;

namespace simple_shapes
{
	void In(sphere &sphereElement, ifstream &ifst)
	{
		try
		{
			ifst >> sphereElement.radius;
			if (sphereElement.radius <= 0 )
				throw exception("Радиус шара должен быть положительным! Работа программы прекращена.");
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	void Out(sphere &sphereElement, ofstream &ofst)
	{
		ofst << "It is Sphere: r = " << sphereElement.radius << ", ";
	}

	double V(sphere &sphereElement)
	{
		return ((sphereElement.radius * sphereElement.radius * sphereElement.radius * 3.14 * 4) / 3);
	}
}