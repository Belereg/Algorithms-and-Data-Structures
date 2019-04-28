#include "stdafx.h";
#if 0
struct nod
{
	int data;
	nod *next;
};

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

	int i, x, n, cnt = 1, m;
	cout << "Nr de noduri pe care vrei sa le aiba lista este ";
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cout << "elementul pe care vrei sa il inserezi in lista este : ";
		cin >> x;
		cout << '\n';
		addLast(head, last, x);
		cout << '\n';
	}
	cout << "lista arata asa: ";
	print(head);

	nod *p = head;
	nod *r = head->next;
	nod *q;
	while (r != NULL)
	{
		m = (p->data + r->data) / 2;
		q = new nod;
		q->data = m;
		p->next = q;
		q->next = r;
		p = r;
		r = r->next;
	}
	cout << '\n';
	print(head);
	system("pause");
}

#endif