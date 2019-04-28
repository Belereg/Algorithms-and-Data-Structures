#include "stdafx.h"
#if 0
struct nod
{
	int data;
	nod *next;
};

#if 1
void addLast(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->data = x;
	p->next = NULL;
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
#endif

#if 1
void addFirst(nod *&head, nod *&last, int x)
{
	//cout << "Elementul care va fi adaugat la inceputul listei este " << x << endl << endl;
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
#endif
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
	nod *head1 = new nod;
	nod *head2 = new nod;

	nod *last1 = new nod;
	nod *last2 = new nod;

	nod *head3 = new nod;
	nod *last3 = new nod;

	head1 = NULL;
	head2 = NULL;

	last1 = NULL;
	last2 = NULL;

	head3 = NULL;
	last3 = NULL;

	int nrx, nry, i, cifra, u = 0;

	cout << "numarul de cifre al primului numar (x) este ";
	cin >> nrx;
	cout <<"\nnumarul de cifre al celui de al doilea numar (y) este ";
	cin >> nry;
	cout << '\n';

	cout << "X = ";
	for (i = 1; i <= nrx; i++)
	{
		cin >> cifra;
		addFirst(head1, last1, cifra);
	}
	cout << "Y = ";
	for (i = 1; i <= nry; i++)
	{
		cin >> cifra;
		addFirst(head2, last2, cifra);
	}

	print(head1);
	cout << "\n\n";
	print(head2);
	cout << "\n\n";
	nod *p1 = head1;
	nod *p2 = head2;
	while (p1 != NULL || p2 != NULL)
	{
		u = u + p1->data + p2->data;
		cout << "u = " << u;
		addFirst(head3, last3, u%10);
		u /= 10;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (u)
	{
		cout << "u = " << u;
		addFirst(head3, last3, u % 10);
		u /= 10;
	}
	cout << "\n\n";
	print(head3);

	system("pause");
}
#endif 