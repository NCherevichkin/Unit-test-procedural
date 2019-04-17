#include <iostream>
#include <fstream>

#include "tetrahedron.h"

using namespace std;

namespace simple_shapes 
{
	void In(tetrahedron &tetrahedronElement, ifstream &ifst)
	{
		try
		{
			ifst >> tetrahedronElement.a;
			if (tetrahedronElement.a <= 0)
				throw exception("Стороны тетраэдра должны быть положительным! Работа программы прекращена.");
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	void Out(tetrahedron &tetrahedronElement, ofstream &ofst)
	{
		ofst << "It is Tetrahedron: a = " << tetrahedronElement.a << ", ";
	}

	double V(tetrahedron &tetrahedronElement)
	{
		return ((tetrahedronElement.a * tetrahedronElement.a * tetrahedronElement.a * sqrt(2)) / 12);
	}
}