#include "stdafx.h"

#if 0

struct nod
{
	int data;
	nod *next;
};

void addFirst(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->data = x;
	if (head == NULL)
	{
		p->next = NULL;
		head = p;
		last = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void addMid(nod *&head, nod *&last, int x, int k)
{
	nod *p = new nod;
	p->data = x;

	nod *temp = head;
	if (k == 1)
	{
		addFirst(head, last, x);
		return;
	}
	if (head == NULL)
	{
		p->next = NULL;
		last = p;
		head = p;
	}
	else
	{
		while (k > 2)
		{
			temp = temp->next;
			k--;
		}
		nod *temp2 = temp->next;
		p->next = temp2;
		temp->next = p;
	}
}

void addLast(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->next = NULL;
	p->data = x;
	if (head == NULL)
	{
		last = p;
		head = p;
	}
	else
	{
		last->next = p;
		last = p;
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

void createList(nod *&head,nod *&last)
{
	int n, i, x;
	cin >> n;
	cout << '\n';
	if (n <= 0)
	{
		cout << "Numar de noduri invalid\n";
		return;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		addLast(head, last, x);
	}
}

void interclasareListe2(nod *&headA,nod *&headB,nod *&lastA,nod *&lastB)
{
	int k = 1;
	nod *pa = headA;
	nod *pb = headB;
	while (pb != NULL)
	{
		k = 1;
		while (pa != NULL && pb->data > pa->data)
		{
			//cout << pa->data << ' ';
			pa = pa->next;
			k++;
		}
		addMid(headA, lastA, pb->data, k);
		pb = pb->next;
		pa = headA;
	}

}

int main()
{
	nod *headA = NULL;
	nod *lastA = NULL;
	nod *headB = NULL;
	nod *lastB = NULL;
	
	cout << "Cate noduri sa aiba lista A ";
	createList(headA, lastA);
	cout << "Cate noduri sa aiba lista B ";
	createList(headB, lastB);
	cout << "A = ";
	print(headA);
	cout << "\nB = ";
	print(headB);
	cout << '\n';
	interclasareListe2(headA, headB, lastA, lastB);
	print(headA);

	system("pause");
}
#endif