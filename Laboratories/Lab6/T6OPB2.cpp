#include "stdafx.h"

struct nod
{
	int data;
	int rank;
	nod *next;
};

void push(nod *&head, int x, int rank)
{
	nod *p = new nod, *temp;
	p->data = x;
	p->next = NULL;
	p->rank = rank;

	if (head == NULL)
	{
		head = p;
	}
	else if (head->rank > rank)
	{
		p->next = head;
		head = p;
	}
	else
	{
		temp = head;
		while (temp->next!=NULL && rank >= temp->next->rank)
			temp = temp->next;
		p->next = temp->next;
		temp->next = p;
	}
}

void print(nod *&head)
{
	nod *p = head;
	while (p)
	{
		cout << "[" << p->data << "][" << p->rank << "]" <<"->";
		p = p->next;
	}
}

void pop(nod *&head)
{
	nod *p = head;
	head = head->next;
	delete p;
}

int main()
{
	nod *head = NULL;
	
	int n, i, x, rank;
	cout << "nr de noduri ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "valoarea : ";
		cin >> x;
		cout << "rank : ";
		cin >> rank;
		push(head, x, rank);

		cout << "acum lista arata asa: ";
		print(head);
		cout << endl;

	}
		
	cout << "cate pop() - uri vrei sa dai ? : ";
	int popp;
	cin >> popp;
	while(popp>0)
	{
		pop(head);
		popp--;
	}
	
	cout << "COADA FINALA : ";
	print(head);
	cout << endl;
	system("pause");
}
