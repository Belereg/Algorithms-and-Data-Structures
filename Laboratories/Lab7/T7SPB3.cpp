#include "stdafx.h"

struct nod
{
	int data;
	nod *stanga;
	nod *dreapta;
};

nod *cautare_nod(nod *p, int val)
{
	if (p->data == val)
		return NULL;
	if (val < p->data)
	{
		if (p->stanga == NULL)
			return p;
		else
			return cautare_nod(p->stanga, val);
	}
	else
	{
		if (p->dreapta == NULL)
			return p;
		else
			return cautare_nod(p->dreapta, val);
	}
}

void insert(nod *&root, int x)
{
	nod *p = new nod;
	p->dreapta = NULL;
	p->stanga = NULL;
	p->data = x;

	if (root == NULL)
	{
		root = p;
		return;
	}

	nod *q = cautare_nod(root, x);

	if (q == NULL)
	{
		cout << "aceeasi valoare\n";
		delete p;
		return;
	}
	if (x < q->data)
		q->stanga = p;
	else
		q->dreapta = p;
}

void SRD(nod *p)
{
	if (p == NULL)
		return;
	SRD(p->stanga);
	cout << p->data << ' ';
	SRD(p->dreapta);
}

int main()
{
	nod *root = NULL;
	int x, n;
	cout << "Cate numere sa fie ordonate? : ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Element : ";
		cin >> x;
		insert(root, x);
	}
	cout << endl;
	SRD(root);
	cout << endl;
	system("pause");
}
