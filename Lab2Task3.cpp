

#include "stdafx.h"
#include "iostream"
using namespace std;



int main()
{
	int n;
	cout << "array size = ";
	cin >> n;
	float *a = new float[n * 2];
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> a[i];
	}
	float x;
	if (n % 2 == 0) 
	{
		x = a[(n / 2) - 1]  + a[n / 2];
	}
	else
	{
		x = a[n / 2];
	}
	int N = n;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 0)
		{
			for (int j = N; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			N++;
			i++;
		}
	}

	int positiv = 0;
	int negativ = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] < 0)
		{
			if (negativ != -1)	negativ++;
		}
		else if (a[i] > 0)
		{
			if (positiv != -1) positiv++;
		}
		if (negativ == 1 || positiv == 2)
		{
			for (int j = i; j < N; j++)
			{
				a[j] = a[j + 1];
			}
			N--;
			i--;
			if (negativ == 1) negativ = -1;
			if (positiv == 2) positiv = -1;
		}

	}

	cout << " new array size = " << N << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "[" << i + 1 << "]:" << a[i] << endl;
	}

	delete[] a;
	system("pause");
    return 0;
}

