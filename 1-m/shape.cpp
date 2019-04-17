#include <iostream>
#include <fstream>

#include "shape.h"

using namespace std;

namespace simple_shapes 
{
	void In(box &boxElement, ifstream &ifst);
	void In(sphere &sphereElement, ifstream &ifst);
	void In(tetrahedron &tetrahedronElement, ifstream &ifst);

	shape* In(ifstream &ifst)
	{
		shape *sp;
		int k;
		try
		{
			ifst >> k;
			switch (k)
			{
			case 1:
				sp = new shape;
				sp->k = shape::key::BOX;
				In(sp->boxElement, ifst);
				break;
			case 2:
				sp = new shape;
				sp->k = shape::key::SPHERE;
				In(sp->sphereElement, ifst);
				break;
			case 3:
				sp = new shape;
				sp->k = shape::key::TETRAHEDRON;
				In(sp->tetrahedronElement, ifst);
				break;
			default:
				throw exception("Во входном файле присутствует неопознанная фигура! Работа программы прекращена.");
			}
			ifst >> sp->temperature;

			return sp;
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	void Out(box &boxElement, ofstream &ofst);
	void Out(sphere &sphereElement, ofstream &ofst);
	void Out(tetrahedron &tetrahedronElement, ofstream &ofst);

	void Out(shape &s, ofstream &ofst) 
	{
		switch (s.k) 
		{
			case shape::key::BOX:
				Out(s.boxElement, ofst);
				break;
			case shape::key::SPHERE:
				Out(s.sphereElement, ofst);
				break;
			case shape::key::TETRAHEDRON:
				Out(s.tetrahedronElement, ofst);
			default:
				break;
				ofst << "Incorrect figure!" << endl;
		}
		ofst << "Melting point = " << s.temperature << " °C, ";
	}

	double V(box &boxElement);
	double V(sphere &sphereElement);
	double V(tetrahedron &tetrahedronElement);

	double V(shape &s)
	{
		switch (s.k) 
		{
			case shape::key::BOX:
				return V(s.boxElement);
			case shape::key::SPHERE:
				return V(s.sphereElement);
			case shape::key::TETRAHEDRON:
				return V(s.tetrahedronElement);
			default:
				return -1;
		}
	}

	bool Compare(shape *first, shape *second) 
	{
		return V(*first) < V(*second);
	}
}