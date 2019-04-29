#include "stdafx.h"

struct nod
{
	int data, LeftSize;
	nod *stanga;
	nod *dreapta;
};

int initLeftSize(nod *&p)
{
	if (p == NULL)
		return 0;

	int sizeL = initLeftSize(p->stanga);
	int sizeR = initLeftSize(p->dreapta);

	p->LeftSize = sizeL;

	return sizeL + sizeR + 1;
}

int cautareValPoz(nod *p, int poz)
{
	if (p == NULL)
		return INT_MIN;
	if (p->LeftSize == poz)
		return p->data;
	if (p->LeftSize > poz)
		return cautareValPoz(p->stanga, poz);
	return cautareValPoz(p->dreapta, poz - p->LeftSize - 1);
}

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
	int n, x, i;
	cout << "Cate noduri sa aiba arborele? : ";
	cin >> n;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << "Element : ";
		cin >> x;
		insert(root, x);
	}
	cout << "\nArborele (SRD) arata asa : ";
	SRD(root);
	cout << endl;
	int nr;
	nr = initLeftSize(root);
	
	cout << "Pozitia din sirul ordonat SRD pe care o cauti : ";
	cin >> nr;
	cout << '\n';
	cout << "Elementul de pe pozitia " << nr << " este : "<< cautareValPoz(root, nr);
	cout << '\n';

	system("pause");
}
