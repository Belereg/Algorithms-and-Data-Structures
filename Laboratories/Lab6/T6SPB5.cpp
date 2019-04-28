#include "stdafx.h"
#if 0
struct nod
{
	int val;
	nod *next, *prev;
};

void addRight(int valoare, nod *&start)
{
	nod *p = new nod;
	p->val = valoare;
	p->next = start->next;
	p->prev = start->prev;
	start->prev->next = p;
	start->next->prev = p;
	start->next = p;
	return;
}

void delLeft(nod *&start)
{
	nod *p;
	p = start->prev;
	if (p->next == p)
	{
		start->next = NULL;
		start->prev = NULL;
		delete p;
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	start->prev = p->prev;
	delete p;

	return;
}

void afisare(nod *start)
{
	nod *p = start;
	if (p->next == NULL)
	{
		cout << "LISTA E VIDAAAAAAAA.\n";
		return;
	}
	cout << "Lista arata asa : ";
	while (p != start->prev)
	{
		p = p->next;
		cout << p->val << " ";
	}
	cout << endl;
	return;
}
int main()
{
	int x, menuChoice, c;
	nod *p, *q, *start = new nod;
	start->val = 0;
	cout << "ADAUGA ELEMENTE IN LISTA PANA LA INTALNIREA LUI 0 : ";
	cin >> x;
	p = new nod;
	start->next = p;
	p->val = x;
	while (x)
	{
		cin >> x;
		if (!x)
			break;
		q = new nod;
		q->val = x;
		q->prev = p;
		p->next = q;
		p = q;
	}
	p->next = start->next;
	start->next->prev = p;
	start->prev = p;

	do
	{
		cout << "(1) Insereaza un nod in dreapta listei.\n";
		cout << "(2) Sterge un nod din stanga listei.\n";
		cout << "(3) Afiseaza lista.\n";
		cout << "(4) Insereaza un nod in dreapta listei.\n";
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "Elementul pe care vrei sa-l adaugi este:  ";
			cin >> x;
			addRight(x, start);
		}
		break;
		case 2:
			delLeft(start);
			break;
		case 3: afisare(start);
			break;
		case 0:
			break;
		default:
			cout << "STOP ITT \n";
			break;
		}
		cout << endl;
	} while (menuChoice);
	system("pause");
}
#endif