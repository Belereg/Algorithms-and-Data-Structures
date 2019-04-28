#include "stdafx.h"

#if 0


struct nod {
	int data;
	nod *next;
};

void addLast(nod *&head, nod *&last, int x)
{
	nod *p = new nod;

	p->next = NULL;
	p->data = x;

	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
}

void addFirst(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->data = x;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void print(nod *&head)
{
	nod *p = head;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}

void swapList(nod *&headA, nod *&headB, nod *&lastA, nod *&lastB)
{
	nod *p = headA;
	while (p != NULL)
	{
		addFirst(headB, lastB, p->data);
		p = p->next;
	}
}

void swapList2(nod *&head, nod *&last, nod *&last2, int &n)
{
	nod *p;
	nod *q;

	last2 = last;
	int m = n - 1;
	while (m--)
	{
		p = head;
		while (p->next != last)
			p = p->next;

		last->next = p;
		last = p;

	}
	head->next = NULL;
}

int main()
{
	nod *headA = NULL;
	nod *lastA = NULL;
	nod *headB = NULL;
	nod *lastB = NULL;
	nod *last2 = NULL;

	int n, i, x;
	cout << "Cate noduri sa aiba lista ";
	cin >> n;
	cout << '\n';
	if(n<=0)
	{
		cout << "Numar de noduri invalid\n"; 
		system("pause");
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		addLast(headA, lastA, x);
	}

	int menuChoise;
	cout << "\nChoose one of the following options :\n";
	cout << "(1) swap A->B \n";
	cout << "(2) swap A->A prin schibarea legaturilor dintre noduri \n";
	cout << "(3) Quit \n";
	cin >> menuChoise;

	switch (menuChoise)
	{
	case 1:
	{
		print(headA);
		cout << endl;
		swapList(headA, headB, lastA, lastB);
		print(headB);
		break;
	}
	case 2:
	{
		swapList2(headA, lastA, last2, n);
		print(last2);
		cout << '\n';
		break;
	}
	case 3:
	{
		break;
	}

	}
	system("pause");
}

#endif