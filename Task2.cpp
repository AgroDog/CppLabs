
#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	float a1, a2, b1, b2, c1, c2;
	cout << "a1:"; cin >> a1;
	cout << "b1:"; cin >> b1;
	cout << "c1:"; cin >> c1;
	cout << "a2:"; cin >> a2;
	cout << "b2:"; cin >> b2;
	cout << "c2:"; cin >> c2;

	if (abs(a1*b2-a2*b1) >= 0.0001)
	{ 
		cout << "The condition is true" << endl;
		float y = (a2*c1 - a1*c2) / (a1*b2 - b1*a2);
		float x;
		if (a1 != 0)
			x = (-b1*y - c1) / a1;
		else
			x = (-b2*y - c2) / a2;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	else
	{
		cout << "The condition is false" << endl;
	}
	system("pause");
    return 0;
}

