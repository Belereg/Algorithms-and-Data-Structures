#include "stdafx.h"

#if 0

struct nod
{
	int data;
	nod *stanga;
	nod *dreapta;
};

nod *cautare_nod(nod *p, int val)
{
	if (p == NULL)
		return NULL;
	if (p->data == val)
		return p;
	nod *q;

	q = cautare_nod(p->stanga, val);
	if (q != NULL)
		return q;
	return cautare_nod(p->dreapta, val);
}

void add(nod *&root, int valoare, int tata)
{
	nod *p = new nod;
	p->data = valoare;
	p->stanga = NULL;
	p->dreapta = NULL;

	if (root == NULL)
	{
		cout << "Root ul a fost setat\n";
		root = p;
		return;
	}
	
	nod *q = cautare_nod(root, tata);
	if (q == NULL)
	{
		cout << "Nu exista un nod cu valoarea asta\n";
		return;
	}
	if (q->dreapta != NULL && q->stanga != NULL)
	{
		cout << "Nodul cu valoare " << p->data << " are deja 2 fii\n";
		return;
	}
	else if (q->dreapta != NULL && q->stanga == NULL)
		q->stanga = p;

	else if (q->dreapta == NULL && q->stanga != NULL)
		q->dreapta = p;
	
	else if (q->dreapta == NULL && q->stanga == NULL)
	{
		cout << "Pe stanga sau pe dreapta ?\n(1) Stanga\n(2) Dreapta\n";
		int x;

		cin >> x;

		if (x == 1)
			q->stanga = p;
		else if(x==2)
			q->dreapta = p;
	}
	
}

void RSD(nod *p)
{
	if (p == NULL)
		return;
	cout << p->data << ' ';
	RSD(p->stanga);
	RSD(p->dreapta);
}

void SRD(nod *p)
{
	if (p == NULL)
		return;
	SRD(p->stanga);
	cout << p->data << ' ';
	SRD(p->dreapta);
}

void SDR(nod *p)
{
	if (p == NULL)
		return;
	SDR(p->stanga);
	SDR(p->dreapta);
	cout << p->data << ' ';
}

int main()
{
	int valoare, tata;
	nod *root = NULL;
	int menuChoice;
	bool repeat = true;

	while (repeat)
	{
		cout << "(1) Adauga nod\n";
		cout << "(2) Afisare RSD\n";
		cout << "(3) Afisare SRD\n";
		cout << "(4) Afisare SDR\n";
		cout << "(5) QUIT\n";


		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "Valoarea nodului: \n";
			cin >> valoare;
			cout << "Al carui nod vrei sa fie fiu? (DACA RADACINA ESTE NULLL, ESTE IRELEVANT)\n";
			cin >> tata;
			add(root, valoare, tata);
			cout << "A fost adaugat nodul cu valoarea " << valoare << endl;
			break;
		}
		case 2:
		{
			RSD(root);
			cout << endl;
			break;
		}
		case 3:
		{
			SRD(root);
			cout << endl;
			break;
		}
		case 4:
		{
			SDR(root);
			cout << endl;
			break;
		}
		case 5:
			repeat = false;
		}
	}
	system("pause");
}
#endif