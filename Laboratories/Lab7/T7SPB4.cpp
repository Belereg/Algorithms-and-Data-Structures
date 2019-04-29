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

void SRD(nod *p,int k1,int k2)
{
	if (p == NULL)
		return;
	SRD(p->stanga,k1,k2);
	if(p->data<=k2 && p->data>=k1)
		cout << p->data << ' ';
	SRD(p->dreapta,k1,k2);
}

int main()
{
	nod *root = NULL;
	int	n, x, k1, k2;
	cout << "cate elemente sa aiba arborele binar de cautare : ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Element : ";
		cin >> x;
		cout << '\n';
		insert(root, x);
	}
	cout << "Cele 2 numere intre care vrei sa cauti :\n";
	cout << "k1 = ";
	cin >> k1;
	cout << '\n';
	cout << "k2 = ";
	cin >> k2;
	cout << '\n';

	SRD(root, k1, k2);
	cout << endl;
	system("pause");
}
