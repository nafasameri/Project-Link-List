// Project Link List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "windows.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class node
{
	node *next;
	int data;
public:
	node(int x, node *n)
	{
		data = x;
		next = n;
	}
	friend class LinkList;
};

class LinkList
{
public:
	static node *InsertInFriest(node *Head, int x)//درج به ابتدا
	{
		node *n = new node(x, NULL);
		n->next = Head;
		Head = n;
		return Head;
	}

	static node *DeleteOfEnd(node *Head)//حذف از انتها
	{
		if (Head == NULL || Head->next == NULL)
		{
			Head->next = NULL;
			Head = NULL;
			return Head;
		}
		else
		{
			node *n = Head;
			while (n->next->next != NULL)
				n = n->next;
			node *temp = n->next;
			n->next = NULL;
			delete temp;
			return Head;
		}
	}

	static void Print(node *Head)//چاپ لیست
	{
		node *n = Head;
		cout << endl;
		if (n != NULL)
			while (n != NULL)
			{
				cout << n->data << "\t";
				n = n->next;
			}
		else
			cout << "Not found item! ):";
	}

	static node *Rev(node *Head)
	{
		node *p = Head;
		node *q = NULL;
		while (p != NULL)
		{
			node *r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		Head = q;
		return Head;
		/*node *p = Head;
		node *r = NULL;
		node *q = p->next;
		while (p != NULL)
		{
		p->next = r;
		r = p;
		p = q;
		q = p->next;
		}
		Head = p;*/
	}

	static node *recRev(node *Head,node *q=NULL)
	{
		if (Head == NULL && q != NULL)
		{
			Head = q;
			return Head;
		}
		else
		{
			node *r = q;
			q = Head;
			node *m = recRev(Head->next, q);
			q->next = r;
			return m;
		}
		/*if ((p == NULL && p->next != NULL) || p != NULL)
		{
			return p;
		}
		else
		{
			node *q = p->next;
			node *m = recRev(p);
			q->next = p;
			p->next = NULL;
			return m;
		}*/
	}
};


void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}

void Show()
{
	int w = 47;
	int h = 9;
	SetConsoleTextAttribute(hConsole, 106);
	for (int i = 0; i < w; i++)
		cout << (char)219;
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		cout << (char)219;
		for (int j = 0; j < w - 2; j++)
			cout << " ";
		cout << (char)219 << endl;
	}
	for (int i = 0; i < w; i++)
		cout << (char)219;
	SetConsoleTextAttribute(hConsole, 107);
	gotoxy(2, 2);
	cout << "Insert one number in firest link list:  'I'";
	gotoxy(2, 3);
	cout << "Delete of end link list:                'D'";
	gotoxy(2, 4);
	cout << "Show number of link list:               'S'";
	gotoxy(2, 5);
	cout << "Reverse link list:                      'R'";
	gotoxy(2, 6);
	cout << "Recursive Reverse link list:            'r'";
	gotoxy(2, 7);
	cout << "Exit:                                   'Q'";
}

void Delete()
{
	gotoxy(0, 11);
	SetConsoleTextAttribute(hConsole, 0);
	for (int i = 0; i < 1000; i++)
		cout << " ";
}

void _tmain()
{
	LinkList LL;
	node *n = NULL;
	Show();
	char choice;
	while (true)
	{
		gotoxy(15, 9);
		SetConsoleTextAttribute(hConsole, 100);
		cout << "Enter your choice";
		gotoxy(22, 10);
		cout << "   ";
		gotoxy(23, 10);
		cin >> choice;
		SetConsoleTextAttribute(hConsole, 42);
		switch (choice)
		{
			case 'I': 
				int num;
				cout << endl << "enter number the your link list: ";
				cin >> num;
				n = LL.InsertInFriest(n, num);
				cout << "Successfully inserted!";
				_getch();
				Delete();
				break;
			case 'D':
				n = LL.DeleteOfEnd(n);
				cout << "Successfully deleted!";
				_getch();
				Delete();
				break;
			case 'S':
				LL.Print(n);
				_getch(); 
				Delete();
				break;
			case 'R':
				n = LL.Rev(n);
				cout << "Successfully reversed!";
				_getch();
				Delete();
				break;
			case 'r':
				n = LL.recRev(n, NULL); 
				cout << "Successfully reversed!";
				_getch();
				Delete();
				break;
			case 'Q':
				cout << "Bye Bye...  (;";
				_getch();
				exit(0);
			default:
				cout << "Enter your chooice again";
				_getch();
				Delete();
				break;
		}
	}
}