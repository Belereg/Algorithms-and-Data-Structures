#include"stdafx.h"

#if 0
struct nod
{
	int data;
	int inaltime;
	nod *stanga;
	nod *dreapta;

};

int inaltime(nod *N)
{
	if (N == NULL)
		return 0;
	return N->inaltime;
}

int maxi(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

nod* newNode(int val)
{
	nod * node = new nod;
	node->data = val;
	node->stanga = NULL;
	node->dreapta = NULL;
	node->inaltime = 1;
	return node;
}

nod *rightRotate(nod *a)
{
	nod *b = a->stanga;
	nod *e = b->dreapta;

	b->dreapta = a;
	a->stanga = e;

	b->inaltime = maxi(inaltime(b->stanga), inaltime(b->dreapta)) + 1;
	a->inaltime = maxi(inaltime(a->stanga), inaltime(a->dreapta)) + 1;

	return b;
}

nod *leftRotate(nod *a)
{
	nod *c = a->dreapta;
	nod *d = c->stanga;

	c->stanga = a;
	a->dreapta = d;

	a->inaltime = maxi(inaltime(a->stanga), inaltime(a->dreapta)) + 1;
	c->inaltime = maxi(inaltime(c->stanga), inaltime(c->dreapta)) + 1;

	return c;
}

int getBalance(nod *p)
{
	if (p == NULL)
		return 0;
	return inaltime(p->stanga) - inaltime(p->dreapta);
}


nod* insert(nod* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->data)
		node->stanga = insert(node->stanga, key);
	else if (key > node->data)
		node->dreapta = insert(node->dreapta, key);
	else
		return node;

	node->inaltime = 1 + maxi(inaltime(node->stanga),
		inaltime(node->dreapta));

	int balance = getBalance(node);

	if (balance > 1 && key < node->stanga->data)
		return rightRotate(node);

	if (balance < -1 && key > node->dreapta->data)
		return leftRotate(node);

	if (balance > 1 && key > node->stanga->data)
	{
		node->stanga = leftRotate(node->stanga);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->dreapta->data)
	{
		node->dreapta = rightRotate(node->dreapta);
		return leftRotate(node);
	}
	return node;
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
#if 0
	if (root == NULL)
		return root;

	root->inaltime = maxi(inaltime(root->stanga), inaltime(root->dreapta)) + 1;
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->stanga) >= 0)
		return rightRotate(root);

	if (balance > 1 && getBalance(root->stanga) < 0)
	{
		root->stanga = leftRotate(root->stanga);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->dreapta) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->dreapta) > 0)
	{
		root->dreapta = rightRotate(root->dreapta);
		return leftRotate(root);
	}
	return root;
#endif
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

void RSD(nod *root)
{
	if (root != NULL)
	{
		cout << root->data << ' ';
		RSD(root->stanga);
		RSD(root->dreapta);
	}
}

int main()
{
	nod *root = NULL;
	int menuChoice, x;
	bool repeat = true;

	while (repeat)
	{
		cout << "(1) adauga nod \n";
		cout << "(2) afisare RSD\n";
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
			root = insert(root, x);
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
#endif