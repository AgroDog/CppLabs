// Task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int n;
	cout << "matrix size = ";
	cin >> n;

	float **matrix = new float*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new float[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "[" << i + 1 << "," << j + 1 << "]:";
			cin >> matrix[i][j];
		}
	}

	float *a = new float[n];
	cout << "Result array syze = " << n << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = matrix[i][i] + matrix[i][n - i - 1];
		cout << "[" << i + 1 << "]:" << a[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] a;
	system("pause");
	return 0;
}

