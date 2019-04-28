#include "stdafx.h"

#if 0
struct nod
{
	int data;
	nod *next;
};

bool empty(nod *&stiva)
{
	if (stiva == NULL)
		return 1;
	else
		return 0;
}

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



int main()
{
	nod *stiva = NULL;
	int n, i, v[100] = { 0 };
	cout << "cati pini sa fie? : \n";
	cin >> n;

	for (i = 1; i <= n; i++)
		cin >> v[i];

	for (i = 1; i <= n; i++)
	{
		if (v[i] == 0)
			continue;
		
		else
		{
			if (stiva == NULL)
				push(v[i], stiva);
			else if (stiva)
			{
				if (v[i] != peek(stiva))
					push(v[i], stiva);
				else
					pop(stiva);
			}
		}
		
	}
	if (empty(stiva) == 1)
		cout << "caz valid";
	else
		cout << "caz invalid";
	system("pause");
}

#endif