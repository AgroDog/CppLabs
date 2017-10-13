

#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{
	int n;
	cout << "array size = ";
	cin >> n;
	int *a = new int[n];
	int even = 0;
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> a[i];
		if (a[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	if (even == odd)
	{
		int result = 1;
		for (int i = 0; i < n; i++)
		{
			result = result * (a[i] + a[n - 1 - i]);
		}
		cout << "result = " << result << endl;
	}
	else
	{
		cout << "even != odd" << endl;
	}
	delete[] a;
	system("pause");

    return 0;
}

