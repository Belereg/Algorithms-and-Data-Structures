#include "stdafx.h"

#if 0

struct nod
{
	int data;
	nod *next;
	nod *prev;
};

void addFirst(nod *&head, nod *&last, int x)
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

void addLast(nod *&head, nod *&last, int x)
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

void addMid(nod *& head, nod *&last, int x, int poz)
{
	nod *p = new nod;
	nod *temp = head;
	int pozz = poz - 1, ok = 0;
	p->data = x;
	if (poz == 1)
	{
		addFirst(head, last, x);
		return;
	}
	else
	{
		while (pozz > 0)
		{
			if (temp->next == NULL)
			{
				temp = temp->prev;
				ok = 1;
			}
			temp = temp->next;
			pozz--;
		}

		if (ok == 1)
		{
			p->next = NULL;
			p->prev = last;
			last->next = p;
			last = p;
		}
		else
		{
			temp->prev->next = p;
			p->prev = temp->prev;
			p->next = temp;
			temp->prev = p;
		}
	}
}

void printAZ(nod *&head)
{
	nod *p = head;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}

}

void printZA(nod *&last)
{
	nod *p = last;
	while (p)
	{
		cout << p->data << ' ';
		p = p->prev;
	}
}

void deleteByPoz(nod *&head,nod *&last,int delPoz)
{
	nod *p = head;
	int delPozz = delPoz - 1;

	while (delPozz > 0)
	{
		p = p->next;
		delPozz--;
	}
	if (p->prev == NULL)
	{
		if (p->next != NULL)
		{
			head = head->next;
			delete p;
			head->prev = NULL;
		}
		else
		{
			head = NULL;
			last = NULL;
			delete p;
		}
	}
	else if (p->next == NULL)
	{
		if (p->prev != NULL)
		{
			last = p->prev;
			delete p;
			last->next = NULL;
		}
		else
		{
			last = NULL;
			head = NULL;
			delete p;
		}
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
}

void deleteByData(nod *&head,nod *&last,int delVal)
{
	nod *p = head;
	int ok = 0;
	while (p->data != delVal)
	{
		if (p->next == NULL)
		{
			ok = 1;
			cout << "DE CE CONTINUI SA INCERCI CHESTII DE ASTEA???\n";
			return;
		}
		p = p->next;
	}
	if (p->prev == NULL)
	{
		if (p->next != NULL)
		{
			head = head->next;
			delete p;
			head->prev = NULL;
		}
		else
		{
			head = NULL;
			last = NULL;
			delete p;
		}
	}
	else if (p->next == NULL)
	{
		if (p->prev != NULL)
		{
			last = p->prev;
			delete p;
			last->next = NULL;
		}
		else
		{
			last = NULL;
			head = NULL;
			delete p;
		}
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
}

int main()
{
	nod *head = new nod;
	nod *last = new nod;

	head = NULL;
	last = NULL;
	int i, n, x, poz, nn, delPoz, delVal;

	cout << "Cate noduri sa aiba lista : ";
	cin >> n;
	nn = n;
	cout << "Elementele listei sunt : ";
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		addLast(head, last, x);
	}
	bool repeat = true;
	int menuChoice;
	while (repeat == true)
	{
		cout << "\nChoose one of the following options :\n";
		cout << "(1) Adaugarea unui element la inceput; \n";
		cout << "(2) Adaugarea unui element la sfarsit; \n";
		cout << "(3) Adaugarea unui element in interiorul listei;\n";
		cout << "(4) Afisarea elementelor listei in ordinea introducerii lor;\n";
		cout << "(5) Afisarea elementelor listei in ordine inversa;\n";
		cout << "(6) Stergerea unui element din lista stiind numarul lui de ordine;\n";
		cout << "(7) Stergerea unui element din lista stiind valoarea lui.\n";
		cout << "(8) Quit\n";

		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
		{
			cout << "Elementul pe care vrei sa il adaugi la INCEPUTUL listei este : ";
			cin >> x;
			addFirst(head, last, x);
			nn++;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Elementul pe care vrei sa il adaugi la SFARSITUL listei este : ";
			cin >> x;
			addLast(head, last, x);
			nn++;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Pe ce pozitie vrei sa adaugi elementul? ";
			cin >> poz;
			if (poz > nn + 1)
			{
				cout << "DE CE TESTEZI ASA CEVA????? ";
				break;
			}
			cout << "Elementul pe care vrei sa il adaugi pe pozitia " << poz << " este : ";
			cin >> x;
			addMid(head, last, x, poz);
			nn++;

			break;
		}
		case 4:
		{
			printAZ(head);
			cout << endl;
			break;
		}

		case 5:
		{
			printZA(last);
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "Elementul de pe care POZITIE vrei sa-l stergi? ";
			cin >> delPoz;
			if (delPoz > nn + 1)
			{
				cout << "DE CE TESTEZI ASA CEVA????? ";
				break;
			}

			deleteByPoz(head, last, delPoz);
			nn--;
			break;

		}
		case 7:
		{
			cout << "Elementul cu ce VALOARE vrei sa-l stergi? ";
			cin >> delVal;
			deleteByData(head, last, delVal);

			break;
		}
		case 8:
		{
			repeat = false;
			break;
		}
		}
	}
	system("pause");
}
#endif