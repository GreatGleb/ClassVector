#include <iostream>
#include <random>
#include <iomanip>
#include "Vectors.h"
#include <cstring>

using namespace std;

template <typename T>

int main() {

	Vectorr <T> c1(13);
	double Arr[10] = {1, 3, 7, 4,8,3,3,2,6,7};
	c1.SetPtr(Arr, 10);
	c1 = c1*2;
	c1 = 1 * c1;
	c1 = c1 + 1;
	c1 = c1 - 13;
	cout << c1 <<  endl;
	Vectorr <T> c2(12);
	double Arr2[12] = { 2, 6, 4, 8,6,6,6,4,2,4,2,2 };
	c2.SetPtr(Arr2, 12);
	cout << c2 << endl;
	Vectorr <T> c3;
	c3.SetCnt(12);
	c3 = c2;
	cout << c3 << endl;
	c3.SetCnt(10);
	c3.SetPtr(Arr, 10);
	cout << c3 << "\n";

	Vectorr <T> i1;
	cin >> i1;
	cout << i1 << endl;

	system("pause");

	return 0;
}
