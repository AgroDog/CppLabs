// Task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;



int main()
{
	int i;
	int sum = 0;
	for (i = 21; i < 100; i++)
	{
		if (i % 3 == 0 && (i % 10 == 2 || i % 10 == 4 || i % 10 == 8))
		{
			sum = sum + i;
		}
	}
	cout << "sum = " << sum << endl;
	system("pause");
    return 0;
}

