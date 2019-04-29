#include "stdafx.h"

struct nod
{
	int data;
	nod *next;
};

void push(int a, nod *&stiva)
{
	nod *p = new nod;
	p->data = a;
	if (stiva == NULL)
	{
		stiva = p;
		p->next = NULL;
	}
	else
	{
		p->next = stiva;
		stiva = p;
	}
}

void afiseaza(nod *&stiva)
{
	nod *p = stiva;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int pop(nod *&stiva)
{
	
	if (stiva == NULL)
	{
		cout << "Stiva vida, return : ";
		return -1;
	}
	else
	{
		nod *p = stiva;
		stiva = stiva->next;
		p->next = NULL;
		return p->data;
	}
}

int peek(nod *&stiva)
{
	if (stiva)
		return stiva->data;
	else
		return -1;
}

int search(int x, nod *&stiva)
{
	nod *p = stiva;
	int k = 0;
	while (p)
	{
		if (p->data == x)
			return k;
		else
			k++;
		p = p -> next;
	}
	return -1;
}

bool empty(nod *&stiva)
{
	if (stiva == NULL)
		return 1;
	else
		return 0;
}

int main()
{
	nod *stiva = NULL;
	int n, menuChoice, i, repeat = 1, x;
	cout << "Cate elemente ? : ";
	cin >> n;
	cout << "elementele sunt : ";
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		push(x, stiva);
	}
	cout << "empty este " << empty(stiva) << endl;
	afiseaza(stiva);
	cout << endl;
	cout << "urmeaza pop : ";
	cout << pop(stiva) << endl;
	afiseaza(stiva);
	cout << "urmeaza peek : ";
	cout << peek(stiva);
	cout << endl;
	cout << "empty este " << empty(stiva) << endl;
	afiseaza(stiva);
	cout << "search value x = ";
	cin >> x;
	cout << search(x, stiva) << endl;
	system("pause");
}
