#include "stdafx.h"
#if 0

struct nod
{
	int data;
	nod *next;
	nod *prev;
};

void pushHead(nod *&head, nod *&last, int x)
{
	nod * p = new nod;
	p->data = x;
	if (head == NULL)
	{
		head = p;
		last = p;
		p->next = NULL;
		p->prev = NULL;
	}
	else
	{
		p->prev = NULL;
		p->next = head;
		head->prev = p;
		head = p;
	}

}

void pushLast(nod *&head, nod *&last, int x)
{
	nod *p = new nod;
	p->data = x;
	if (head == NULL)
	{
		head = p;
		last = p;
		p->next = NULL;
		p->prev = NULL;
	}
	else
	{
		last->next = p;
		p->prev = last;
		last = p;
		p->next = NULL;
	}

}

void printAZ(nod *&head)
{
	nod *p = head;
	if (head == NULL)
	{
		cout << "lista e goala";

	}
	else
	{
		while (p)
		{
			//cout << "az ";
			cout << p->data << ' ';
			p = p->next;
		}
	}
}

void printZA(nod *&last)
{
	nod *p = last;
	if (last == NULL)
		cout << "lista e goala";
	else
	{
		while (p)
		{
			
			cout << p->data << ' ';
			p = p->prev;
		}
	}
}

void popHead(nod *&head)
{
	nod *p = head;
	if (head->next == NULL)
	{
		cout << "2";
		//last = NULL;
		head = NULL;
		delete p;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
		delete p;
	}

}
void popLast(nod *&last)
{
	if (last == NULL)
	{
		cout << "LISTA VIDAAA";
		return;
	}
	nod *p = last;
	last = last->prev;
	if (last != NULL)
		last->next = NULL;
	delete p;
}

int main()
{
	nod *head = new nod;
	nod *last = new nod;

	head = NULL;
	last = NULL;
	int i, n, x, poz, nn;

	cout << "Cate noduri sa aiba lista : ";
	cin >> n;
	nn = n;
	cout << "Elementele listei sunt : ";
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		pushLast(head, last, x);
	}
	bool repeat = true;
	int menuChoice;
	while (repeat == true)
	{
		cout << "\nChoose one of the following options :\n";
		cout << "(1) Adaugarea unui element la inceput; \n";
		cout << "(2) Adaugarea unui element la sfarsit; \n";
		cout << "(3) Stergerea unui element de la inceputul cozii;\n";
		cout << "(4) Stergerea unui element de la sfarsitul cozii;\n";
		cout << "(5) Quit\n";
		cout << "(6) Afisare de la HEAD la LAST si de la LAST la HEAD\n";

		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "Elementul pe care vrei sa il adaugi la INCEPUTUL cozii este : ";
			cin >> x;
			pushHead(head, last, x);
			nn++;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Elementul pe care vrei sa il adaugi la SFARSITUL cozii este : ";
			cin >> x;
			pushLast(head, last, x);
			nn++;
			cout << endl;
			break;
		}
		case 3:
		{
			popHead(head);
			break;
		}
		case 4:
		{
			popLast(last);
			break;
		}
		case 5:
		{
			repeat = false;
			break;
		}

		case 6:
		{
			printAZ(head);
			cout << endl;
			printZA(last);
			cout << endl;
			break;
		}
		}
	}
	system("pause");
}
#endif