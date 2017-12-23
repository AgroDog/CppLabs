

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
	Note *Prev, *Next;
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

struct Notes
{
	Note *First = NULL;
	int Count = 0;

	void AddNote(Note *newNote)
	{
		Note *befor = NULL;
		Note *after = NULL;
		Note *note = First;
		while (note != NULL)
		{
			if (NoteCmp(newNote, note) < 0)
			{
				after = note;
				befor = note->Prev;
				break;
			}
			else
			{
				befor = note;
				after = NULL;
			}
			note = note->Next;
		}

		newNote->Prev = befor;
		if (befor != NULL)
			befor->Next = newNote;
		newNote->Next = after;
		if (after != NULL)
			after->Prev = newNote;

		if (newNote->Prev == NULL)
			First = newNote;
		Count++;
	}

	void Clear()
	{
		Note *note;
		while (First != NULL)
		{
			note = First;
			First = First->Next;
			delete note;
		}
		Count = 0;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	Notes notes;
	Note *note;
	while (true)
	{
		note = new Note();
		cout << "Запись №" << notes.Count + 1 << endl;
		cout << "\tФамилия: ";
		cin.getline(note->Surname, sizeof(note->Surname));
		cout << "\tИмя: ";
		cin.getline(note->Name, sizeof(note->Name));
		cout << "\tТелефон: ";
		cin.getline(note->Phone, sizeof(note->Phone));
		cout << "\tДата рождения: " << endl;
		cout << "\t\tДень: ";
		cin >> note->Date[0];
		cout << "\t\tМесяц: ";
		cin >> note->Date[1];
		cout << "\t\tГод: ";
		cin >> note->Date[2];
		notes.AddNote(note);

		cin.ignore();
		cout << endl << "Esc - прервать ввод, Enter - продолжить" << endl << endl;
		char ch;
		do
		{
			ch = _getch();
		} while (ch != 27 && ch != 13);
		if (ch == 27)
			break;
	}

	cout << "Записи отсортированы по трем первым цифрам номера телефона" << endl;
	note = notes.First;
	int noteNum = 0;
	while (note != NULL)
	{
		noteNum++;
		cout << "Запись №" << noteNum << endl;
		cout << "\tФамилия: " << note->Surname << endl;
		cout << "\tИмя: " << note->Name << endl;
		cout << "\tТелефон: " << note->Phone << endl;
		cout << "\tДата рождения: " << note->Date[0] << "." << note->Date[1] << "." << note->Date[2] << endl;
		note = note->Next;
	};


	char key[256];
	cout << "Поиск записи по Фамилии: ";
	cin.getline(key, sizeof(key));
	Note *pFinded = NULL;
	note = notes.First;
	while (note != NULL)
	{
		if (_stricmp(key, note->Surname) == 0)
		{
			pFinded = note;
			break;
		}
		note = note->Next;
	}

	if (pFinded != NULL)
	{
		cout << "Запись с фамилией " << key << " найдена" << endl;
		cout << "\tФамилия: " << pFinded->Surname << endl;
		cout << "\tИмя: " << pFinded->Name << endl;
		cout << "\tТелефон: " << pFinded->Phone << endl;
		cout << "\tДата рождения: " << pFinded->Date[0] << "." << pFinded->Date[1] << "." << pFinded->Date[2] << endl;
	}
	else
	{
		cout << "Запись с фамилией " << key << " отсутствует" << endl;
	}

	notes.Clear();
	system("pause");
	return 0;
}