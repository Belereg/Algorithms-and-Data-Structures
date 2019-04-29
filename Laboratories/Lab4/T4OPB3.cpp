#include "stdafx.h"

struct nod
{
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

void sharing(nod *&head, nod *&headA, nod*&headB)
{
	nod *A, *B;

	headA = head;
	A = headA;
	
	B = head->next;
	if (head)
	{
		headB = head->next;
		B = headB;
	}
	while ((A->next && A) && (B->next && B))
	{
		A->next = B->next;
		A = A->next;
		B->next = A->next;
		B = B->next;
	}
	if (B)
		B->next = NULL;
	if (A)
		A->next = NULL;

}

void createList(nod *&head, nod *&last)
{
	int n, x, i;
	cout << "Nr de noduri pe care vrei sa-l aiba lista C: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Ai ales 0 sau mai putine noduri";
		return;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		addLast(head, last, x);
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

int main()
{
	nod *headA = NULL;
	nod *headB = NULL;
	nod *head = NULL;
	nod *last = NULL;

	createList(head, last);
	cout << '\n';
	sharing(head, headA, headB);

	print(headA);
	cout << endl;
	print(headB);
	cout << endl;
	cout << '\n';

	system("pause");
}
