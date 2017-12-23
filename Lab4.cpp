

#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include "Windows.h"
#include <conio.h>

using namespace std;

struct Note
{
	char Surname[256];
	char Name[256]; 
	char Phone[128]; 
	unsigned short Date[3];
};

char* GetFirstNum(const char* phone, int count)
{
	char* ret = new char[count + 1];
	memset(ret, 0, count + 1);
	for (int i = 0; i < (int)strlen(phone); i++)
	{
		if ((int)strlen(ret) < count)
		{
			if (isdigit(phone[i]))
			{
				strncat_s(ret, count + 1, &phone[i], 1);
			}
		}
		else
			break;
	}
	return ret;
}

int NoteCmp(const void *note1, const void *note2)
{
	char* p1 = GetFirstNum(((Note*)note1)->Phone, 3);
	char* p2 = GetFirstNum(((Note*)note2)->Phone, 3);

	if (atof(p1) == atof(p2))
		return 0;
	else if (atof(p1) > atof(p2))
		return 1;
	else
		return -1;

	delete p1;
	delete p2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//setlocale(LC_ALL, "Russian_Russia.1251");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	int const maxCount = 8;
	Note notes[maxCount];
	int realCount = 0;
	for (int i = 0; i < maxCount; i++)
	{
		cout << "������ �" << i + 1 << endl;
		cout << "\t�������: ";
		cin.getline(notes[i].Surname, sizeof(notes[i].Surname));
		cout << "\t���: ";
		cin.getline(notes[i].Name, sizeof(notes[i].Name));
		cout << "\t�������: ";
		cin.getline(notes[i].Phone, sizeof(notes[i].Phone));
		cout << "\t���� ��������: " << endl;
		cout << "\t\t����: ";
		cin >> notes[i].Date[0];
		cout << "\t\t�����: ";
		cin >> notes[i].Date[1];
		cout << "\t\t���: ";
		cin >> notes[i].Date[2];
		realCount++;

		cin.ignore();
		cout << endl << "Esc - �������� ����, Enter - ����������" << endl << endl;
		char ch;
		do
		{
			ch = _getch();
		} while (ch != 27 && ch != 13);
		if (ch == 27)
			break;
	}

	qsort(notes, realCount, sizeof(Note), NoteCmp);

	cout << "������ ������� ������������ �� ���� ������ ������ ������ ��������" << endl;
	for (int i = 0; i < realCount; ++i)
	{
		cout << "������ �" << i + 1 << endl;
		cout << "\t�������: " << notes[i].Surname << endl;
		cout << "\t���: " << notes[i].Name << endl;
		cout << "\t�������: " << notes[i].Phone << endl;
		cout << "\t���� ��������: " << notes[i].Date[0] << "." << notes[i].Date[1] << "." << notes[i].Date[2] << endl;
	}

	char key[256];
	cout << "����� ������ �� �������: ";
	cin.getline(key, sizeof(key));
	Note *pFinded = NULL;

	for (int i = 0; i < realCount; ++i)
	{
		if (_stricmp(key, notes[i].Surname) == 0)
		{
			pFinded = &notes[i];
			break;
		}
	}
	if (pFinded != NULL)
	{
		cout << "������ � �������� " << key << " �������" << endl;
		cout << "\t�������: " << pFinded->Surname << endl;
		cout << "\t���: " << pFinded->Name << endl;
		cout << "\t�������: " << pFinded->Phone << endl;
		cout << "\t���� ��������: " << pFinded->Date[0] << "." << pFinded->Date[1] << "." << pFinded->Date[2] << endl;
	}
	else
	{
		cout << "������ � �������� " << key << " �����������" << endl;
	}

	system("pause");
	return 0;
}