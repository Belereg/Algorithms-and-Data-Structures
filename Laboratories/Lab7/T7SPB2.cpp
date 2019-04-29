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
		cout << "same value\n";
		delete p;
		return;
	}

	if (x < q->data)
		q->stanga = p;
	else
		q->dreapta = p;
}

bool search(nod *p, int x)
{
	if (p == NULL)
		return false;
	if (x < p->data)
		if (p->stanga == NULL)
			return false;
		else
			return search(p->stanga, x);

	if (x > p->data)
		if (p->dreapta == NULL)
			return false;
		else
			return search(p->dreapta, x);
	return true;
}

int findMax(nod *&p)
{
	if (p == NULL)
		return INT_MIN;

	if (p->dreapta != NULL)
		return findMax(p->dreapta);

	return p->data;
}

void RSD(nod *p)
{
	if (p == NULL)
		return;
	cout << p->data << endl;
	RSD(p->stanga);
	RSD(p->dreapta);
}

void SRD(nod *p)
{
	if (p == NULL)
		return;
	SRD(p->stanga);
	cout << p->data << endl;
	SRD(p->dreapta);
}

void SDR(nod *p)
{
	if (p == NULL)
		return;
	SDR(p->stanga);
	SDR(p->dreapta);
	cout << p->data << endl;
}

nod *find_min(nod *root)
{
	while (root->stanga != NULL)
		root = root->stanga;
	return root;
}

nod *delete_nod(nod *root, int val)
{
	if (root == NULL)
		return NULL;
	else if (val < root->data)
		root->stanga = delete_nod(root->stanga, val);
	else if (val > root->data)
		root->dreapta = delete_nod(root->dreapta, val);
	else
	{
		if (root->stanga == NULL && root->dreapta == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}
		else if (root->stanga == NULL)
		{
			nod *temp = root;
			root = root->dreapta;
			delete temp;
		}
		else if (root->dreapta == NULL)
		{
			nod *temp = root;
			root = root->stanga;
			delete temp;
		}
		else
		{
			nod *temp = find_min(root->dreapta);
			root->data = temp->data;
			root->dreapta = delete_nod(root->dreapta, temp->data);

		}
	}
	return root;

}

int main()
{
	int menuChoice, x;
	bool repeat = true;

	nod *root = NULL;

	while (repeat)
	{
		cout << "(1) adauga nod \n";
		cout << "(2) afisare RSD\n";
		cout << "(3) afisare SRD\n";
		cout << "(4) afisare SDR\n";
		cout << "(5) QUIT\n";
		cout << "(6) search for node\n";
		cout << "(7) cauta nodul cu valoare maxima in arbore\n";
		cout << "(8) sterge un element din arbore\n";

		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "ce elemente vrei sa adaugi : ";
			cin >> x;
			insert(root, x);
			cout << "elementul " << x << " a fost adaugat\n";
			break;
		}
		case 2:
		{
			RSD(root);
			break;
		}
		case 3:
		{
			SRD(root);
			break;
		}
		case 4:
		{
			SDR(root);
			break;
		}
		case 5:
			repeat = false;
			break;
		case 6:
		{
			cout << endl;
			int y;
			cout << "Elementul cautat : ";
			cin >> y;
			cout << endl;
			cout << search(root, y);
			cout << endl;
			break;
		}
		case 7:
		{
			if (findMax(root) != INT_MIN)
				cout << "Elementul maxim este : " << findMax(root) << endl;
			else
				cout << "Arborele nu are radacina \n\n";
			break;
		}
		case 8:
		{
			cout << "Elementul pe care vrei sa-l stergi este : ";
			int x;
			cin >> x;
			cout << '\n';
			delete_nod(root, x);
			break;
		}
		}
	}
	system("pause");
}
