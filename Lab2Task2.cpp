
#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n;
	cout << "array size = ";
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) 
	{ 
		cout << "[" << i + 1 << "]:";
		cin >> a[i];
	}
	int imax = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] > a[imax])
		{
			imax = i;
		}
	}
	for (int i = 0; i < imax; i++) 
	{
		if ((i+1) % 2 == 0) 
		{
			a[i] = a[i] * a[imax];
		}
	}

	cout << "new array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:" << a[i] << endl;
	}

	delete[] a;
	system("pause");
    return 0;
}

