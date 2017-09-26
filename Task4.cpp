// Task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int num;
	int old;
	bool increased = false;
	bool decreased = false;
	cout << "num:"; cin >> num;
	old = num;

	while (num != 0)
	{
		if (num < old)
		{
			decreased = true;
		}
		else
		{
			if (num > old)
			{
				increased = true;
			}
		}
		old = num;
		cout << "num:"; cin >> num;
	}

	if (decreased == true)
	{
		cout << "No" << endl;
	}
	else
	{
		if (increased == true)
		{
			cout << "Yes" << endl;
		}
	}
	system("pause");
    return 0;
}

