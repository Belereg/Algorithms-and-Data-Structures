#include "stdafx.h"

struct nod
{
	int data;
	nod *next, *prev;
};

void addByPoz(int x, int poz, nod *&start)
{
	int n;
	nod *p, *q, *add;
	p = start->prev;
	q = p->next;
	n = 1;

	while (n < poz)
	{
		p = q;
		q = q->next;
		n++;
	}
	add = new nod;add->data = x;add->prev = p;add->next = q;p->next = add;q->prev = add;
	if (add->prev == start->prev)
		start->next = add;
	else if (add->next == start->next)
		start->prev = add;
}

void delByData(int val, nod *&start)
{
	nod *p, *q, *r;
	p = start->next;
	if (p->next == p && p->data == val)
	{
		start->next = NULL;
		start->prev = NULL;
		delete p;
		system("pause");
		return;
	}
	do
	{
		if (p->data == val)
		{
			q = p->prev;
			r = p->next;
			q->next = r;
			r->prev = q;
			if (p == start->next)
				start->next = r;
			else if (p == start->prev)
				start->prev = q;
			delete p;
			return;
		}
		p = p->next;
	} while (p != start->next);
	cout << "\nWHY DO U TRY THISSS.\n";
	return;
}

void afisare(nod *start)
{
	if (start->next == NULL)
	{
		cout << "LISTA VIDAAA.\n";
		return;
	}
	nod *p = start->next;
	cout << "Lista este : ";
	do
	{
		cout << p->data << " ";
		p = p->next;
	}
	while (p != start->next);
	cout << endl;
	return;
}

int main()
{
	int x, menuChoice, poz;
	nod *p, *q, *start = new nod;
	start->data = 0;
	cout << "introdu valori in lista pana la intalnirea lui 0 :\n";
	cin >> x;
	p = new nod;
	start->next = p;
	p->data = x;

	while (x)
	{
		cin >> x;
		if (!x)
			break;
		q = new nod;
		q->data = x;
		q->prev = p;
		p->next = q;
		p = q;
	}
	p->next = start->next;
	start->next->prev = p;
	start->prev = p;
	do
	{
		cout << "(1) Adauga nod in lista in functie de pozitie.\n";
		cout << "(2) Sterge nod din lista in functie de valoare.\n";
		cout << "(3) Afiseaza lista.\n";
		cout << "(0) Quit.";

		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "Elementul pe care vrei sa il adaugi in lista este : ";
			cin >> x;
			cout << "Pe ce pozitie vrei sa adaugi elementul in lista? : ";
			cin >> poz;
			addByPoz(x, poz, start);
		}
		break;
		case 2:
		{
			cout << "Ce valoare vrei sa stergi din lista? : ";
			cin >> poz;
			
			delByData(poz, start);
			
		}
		break;
		case 3: afisare(start);
			break;
		case 4:
		{
			break;
			system("pause");
			return 0;
		}
		default:
			cout << "INVALID.\n";
			break;
		}
		cout << endl;
	} while (menuChoice);
	system("pause");
}
