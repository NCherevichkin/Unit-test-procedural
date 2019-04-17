#include <iostream>
#include <fstream>
#include <cstdlib>

#include "container.h"

using namespace std;

namespace simple_shapes
{
	void Init(container &c);
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void Sort(container &c);
	void OutBoxes(container &c, ofstream &ofst);
}

using namespace simple_shapes;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 3)
	{
		cout << "Incorrect command line! Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);

	if (!ifst.is_open())
	{
		cout << "Невозможно открыть входной файл, в директории нет файла с именем: " << argv[1] << endl;
		system("pause");
		exit(1);
	}

	ofstream ofst(argv[2]);

	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	ofst << "Sorted container." << endl;
	Sort(c);
	Out(c, ofst);
	OutBoxes(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	
	return 0;
}