
#include "stdafx.h"
#include <iostream> 

using namespace std;
int main()
{
	double x, y, z, a, b;
	cout << "x:"; cin >> x;
	cout << "y:"; cin >> y;
	cout << "z:"; cin >> z;

	a = log(abs((y-sqrt(abs(x)))*(x-y/(z+x*x/4))));
	cout << "a = " << a << endl;

	b = x - pow(x, 2) /( 1 * 2 * 3) + pow(x, 5) / (1 * 2 * 3 * 4 * 5);
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}

