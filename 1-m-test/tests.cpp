#include <string>

#include "pch.h"

#include "../1-m/box.cpp"
#include "../1-m/sphere.cpp"
#include "../1-m/tetrahedron.cpp"
#include "../1-m/shape.cpp"
#include "../1-m/container.cpp"
#include "../1-m/sphere.h"

using namespace std;

using namespace simple_shapes;

string GetEntityStringView(shape temp)
{
	switch (temp.k)
	{
		case shape::key::BOX:
			return to_string(temp.boxElement.x) + " " + to_string(temp.boxElement.y) + " " + to_string(temp.boxElement.z) + " " + to_string(temp.temperature);
		case shape::key::SPHERE:
			return to_string(temp.sphereElement.radius) + " " + to_string(temp.temperature);
		case shape::key::TETRAHEDRON:
			return to_string(temp.tetrahedronElement.a) + " " + to_string(temp.temperature);
		default:
			return "";
	}
}

TEST(ReadTests, IsReadCorrect)
{
	container actual, expected;
	Init(actual);
	Init(expected);
	In(actual, ifstream("../1-m-test/TestFile.txt"));
	AddElement(expected, new shape({ shape::key::BOX, 100, { 10, 20, 30 } }));
	AddElement(expected, new shape({ shape::key::SPHERE, 228, { 25 } }));
	AddElement(expected, new shape({ shape::key::TETRAHEDRON, 1996, { 18 } }));
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(GetEntityStringView((*(actual.cont[i]))), GetEntityStringView(*(expected.cont[i])));
}

TEST(VTests, IsVCorrect)
{
	container elements;
	Init(elements);	
	In(elements, ifstream(("../1-m-test/TestFile.txt")));
	// при работе с дробными числами мы не можем проверить точное соответствие, посему вводим погрешность
	EXPECT_TRUE(V((*(elements.cont[0]))) -  6000 < 0.0000001);
	EXPECT_TRUE(V((*(elements.cont[1]))) - 65416.7 < 0.0000001);
	EXPECT_TRUE(V((*(elements.cont[2]))) -  687.308 < 0.0000001);
}

TEST(SortTests, IsSortCorrect)
{
	container actual, expected;
	Init(actual);
	Init(expected);
	In(actual, ifstream("../1-m-test/TestFile.txt"));
	Sort(actual);
	AddElement(expected, new shape({ shape::key::SPHERE, 228, { 25 } }));
	AddElement(expected, new shape({ shape::key::BOX, 100, { 10, 20, 30 } }));
	AddElement(expected, new shape({ shape::key::TETRAHEDRON, 1996, { 18 } }));
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(GetEntityStringView((*(actual.cont[i]))), GetEntityStringView(*(expected.cont[i])));
}

bool CompareFiles(string path1, string path2)
{
	string temp;
	ifstream File1(path1);
	vector<string> File1Lines;
	while (File1)
	{
		getline(File1, temp);
		File1Lines.push_back(temp);
	}
	ifstream File2(path2);
	vector<string> File2Lines;
	while (File2)
	{
		getline(File2, temp);
		File2Lines.push_back(temp);
	}
	if (File1Lines.size() != File2Lines.size())
		return false;
	for (int i = 0; i < (int)File1Lines.size(); i++)
		if (File1Lines[i] != File2Lines[i])
			return false;
	return true;
}

TEST(WriteTests, IsWriteCorrect)
{
	container data;
	Init(data);
	AddElement(data, new shape({ shape::key::BOX, 100, { 10, 20, 30 } }));
	AddElement(data, new shape({ shape::key::SPHERE, 228, { 25 } }));
	AddElement(data, new shape({ shape::key::TETRAHEDRON, 1996, { 18 } }));
	Out(data, ofstream(("../1-m-test/ActualWriteFile.txt")));
	EXPECT_TRUE(CompareFiles("../1-m-test/ActualWriteFile.txt", "../1-m-test/ExpectedWriteFile.txt"));
}

TEST(WriteTests, IsFilteredWriteCorrect)
{
	container data;
	Init(data);
	AddElement(data, new shape({ shape::key::BOX, 100, { 10, 20, 30 } }));
	AddElement(data, new shape({ shape::key::SPHERE, 228, { 25 } }));
	AddElement(data, new shape({ shape::key::BOX, 200, { 69, 96, 228 } }));
	AddElement(data, new shape({ shape::key::TETRAHEDRON, 1996, { 18 } }));
	AddElement(data, new shape({ shape::key::BOX, 300, { 192, 168, 1 } }));
	OutBoxes(data, ofstream(("../1-m-test/ActualFilteredWriteFile.txt")));
	EXPECT_TRUE(CompareFiles("../1-m-test/ActualFilteredWriteFile.txt", "../1-m-test/ExpectedFilteredWriteFile.txt"));
}