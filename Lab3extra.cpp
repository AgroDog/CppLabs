


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	struct Abonent
	{
		string F;
		string I;
		string O;
		float Sum = 0;
		int n = 0;
	};

	setlocale(LC_ALL, "Russian");

	string inFileName = "INPUT.TXT";
	string outFileName = "OUTPUT.TXT";
	ifstream input(inFileName);
	ofstream output(outFileName);
	if (input.is_open())
	{
		string line;
		Abonent minAbonet;
		int lineNum = 0;
		while (getline(input, line))
		{
			cout << line << endl;
			lineNum++;
			
			Abonent curAbonent;
			istringstream strStream(line);
			getline(strStream, curAbonent.F, ';');
			getline(strStream, curAbonent.I, ';');
			getline(strStream, curAbonent.O, ';');

			string lex;
			getline(strStream, lex, ';');
			float nextValue;
			float lastValue = stof(lex);
			while (getline(strStream, lex, ';'))
			{
				nextValue = stof(lex);
				curAbonent.Sum = curAbonent.Sum + (nextValue - lastValue);
				curAbonent.n++;
				lastValue = nextValue;
			}
			if (lineNum == 1)
			{
				minAbonet = curAbonent;
			}
			else
			{
				if (curAbonent.Sum / curAbonent.n > minAbonet.Sum / minAbonet.n)
				{
					minAbonet = curAbonent;
				}
			}
		}
		cout << endl << minAbonet.F << " " << minAbonet.I << " " << minAbonet.O << " " << endl;
		cout << "среднее потребление:" << minAbonet.Sum / minAbonet.n << endl;
		output << minAbonet.F << " " << minAbonet.I << " " << minAbonet.O << " " << endl;
		output << "среднее потребление:" << minAbonet.Sum / minAbonet.n << endl;
	}
	else
	{
		cout << "File " << inFileName << " not opened" << endl;
	}
	input.close();
	output.close();

	system("pause");
	return 0;
}

