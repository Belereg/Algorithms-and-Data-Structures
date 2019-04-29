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

int pop(nod *&stiva)
{

	if (stiva == NULL)
		return -1;
	
	else
	{
		nod *p = stiva;
		stiva = stiva->next;
		p->next = NULL;
		return p->data;
	}

}

int main()
{
	char s[100];
	cout << "sirul W este  : ";
	cin.get(s, 100);

	int i = 0, k = 0, ii = -1, ok = 1;
	nod *stiva = NULL;
	while (s[i])
	{
		if (s[i] == '(' && k == 0)
		{
			
			ok = 2;
			push(1, stiva);

		}
		else if (s[i] == '(' && k < 0)
			k++;
		else if (s[i] == ')' && k == 0 && stiva)
		{
			pop(stiva);
		}
		else if (s[i] == ')' && k <= 0 && !stiva)
		{
			if (ok == 1)
			{
				ok = 0;
				ii = i;
			}
			if (ok == 2)
			{
				ok = 0;
				ii = i;
			}
			k--;
		}
		i++;
	}

	if (stiva == NULL && k == 0)
		cout << "corect parantezat\n";
	else if (stiva == NULL && k < 0)
		cout << "nu e corect parantezat, iar paranteza gresita este pe pozitia : " << ii << endl;
	else if (stiva != NULL && k > 0)
		cout << "STRIGAAA\n";
	system("pause");
}
