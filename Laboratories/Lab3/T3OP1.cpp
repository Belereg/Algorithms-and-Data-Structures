#include "stdafx.h"

#if 0
struct nod
{
	int data;
	nod *next;
};

struct pol
{
	int gr, coef;
	pol *next;
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

void addLast(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->data = x;
	if (head == NULL)
	{
		p->next = NULL;
		last = p;
		head = p;
	}
	else
	{
		last->next = p;
		last = p;
		p->next = NULL;
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

void print(nod *head)
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
	nod *head = new nod;
	nod *last = new nod;
	head = NULL;
	last = NULL;

	int n, i, x, cnt = 0;
	cout << "cate noduri sa aibe lista? : ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "elementul pe care vrei sa il inserezi este : ";
		cin >> x;
		nod *r = new nod;
		r->data = x;
		r->next = NULL;
		cout << '\n';

		if (head == NULL || x <= head->data)
			addFirst(head, last, x);
		else if (x >= last->data)
			addLast(head, last, x);
		else
		{
			cnt = 0;
			nod *p = head;
			while (x >= p->next->data)
			{
				p = p->next;
				cnt++;
			}
			nod *r = p->next;
			addMid(head, last, x, cnt + 2);
		}
	}
	print(head);
	system("pause");
}
#endif