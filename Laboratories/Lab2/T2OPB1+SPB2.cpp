
#include "stdafx.h"

#if 0
struct nod {
	int data;
	nod *next;
};

#if 1
void addFirst(nod *&head, nod *&last, int x)
{
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

#if 1
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
#endif

#if 1
void addMid(nod *&head, nod *&last, int x, int k)
{
	nod *p = new nod;
	p->data = x;

	nod *temp = head;
	if (k == 1)
	{
		addFirst(head, last, x);
		return;
	}
	if (head == NULL)
	{
		p->next = NULL;
		last = p;
		head = p;
	}
	else
	{
		while (k > 2)
		{
			temp = temp->next;
			k--;
		}
		nod *temp2 = temp->next;
		p->next = temp2;
		temp->next = p;
	}
}
#endif

#if 1
void searchVal(nod *&head, int val)
{
	cout << '\n';
	nod *p = head;

	while (p->data != val && p->next != NULL)
		p = p->next;
	if (p->data == val)
		cout << "Valoarea " << val << " a fost gasita in lista" << '\n';
	else
		cout << "Valoarea " << val << " nu a fost gasita in lista" << '\n';
}
#endif


#if 1
void searchPoz(nod *&head, int poz)
{
	nod *p = head;
	int ppoz = poz - 1;
	if (poz < 1)
	{
		cout << "Nodul cu pozitia " << poz << " nu exista." << '\n';
		return;
	}
	while (ppoz && p != NULL)
	{
		p = p->next;
		ppoz--;
	}
	if (p != NULL)
		cout << "Nodul cu pozitia " << poz << " exista" << '\n';
	else
		cout << "Nodul cu pozitia " << poz << " nu exista." << '\n';

}
#endif

#if 1
void deleteVal(nod *&head, nod *&last, int deldata)
{
	nod *p = head;

	if (deldata == p->data)
	{
		head = p->next;
		delete p;
		return;
	}
	if (last->data == deldata)
	{
		while (p->next != last)
			p = p->next;
		delete last;
		last = p;
		last->next = NULL;
		return;
	}

	while (p->next != NULL && p->next->data != deldata)
		p = p->next;
	nod *r = p->next;
	nod *t = r->next;
	p->next = r->next;
	delete r;
}
#endif

#if 1
void deletePoz(nod *&head, int delpoz)
{
	nod *p = head;
	int ppoz = delpoz - 2;
	if (delpoz < 1)
	{
		cout << "Nu exista niciun nod pe pozitia " << delpoz << '\n';
		return;
	}

	if (delpoz == 1)
	{
		head = head->next;
		delete p;
		return;
	}
	while (ppoz)
	{
		p = p->next;
		ppoz--;
	}
	nod *r = p->next;
	p->next = r->next;
	delete r;
}
#endif

#if 1
void deleteAll(nod *&head)
{
	nod *p = head;
	while (head != NULL)
	{
		head = head->next;
		delete p;
		p = head;
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
void parImpar(nod *&head,int &nrPare, float &ma,float &impare)
{
	nod *p = head;
	while (p != NULL)
	{
		if (p->data % 2 == 0)
			nrPare++;
		else
		{
			ma += p->data;
			impare++;
		}
		p = p ->next;
	}
	ma = ma / impare;
}
int main()
{
	nod *head = new nod;
	nod *last = new nod;
	head = NULL;
	last = NULL;

	int n, i, x, k, y, val, poz, delVal, delPoz, kk = 1, nrPare = 0;
	float ma = 0, impare = 0;
	bool repeat = true;

	while (repeat == true)
	{
		int menuChoice;
		cout << "Please select an option" << '\n' << '\n';
		cout << "(1) Add nodes to the beginning of the list. " << '\n';
		cout << "(2) Add nodes at the end of the list. " << '\n';
		cout << "(3) Add nodes at a specified position in the list. " << '\n';
		cout << "(4) Search for a node by its data information and see if it exists in the list. " << '\n';
		cout << "(5) Search for a node by its position in the list and see if it exists in the list." << '\n';
		cout << "(6) Remove a node from the list, by its data information. " << '\n';
		cout << "(7) Remove a node from the list from a specified location. " << '\n';
		cout << "(8) Remove all the nodes from the list. " << '\n';
		cout << "(9) Suplimentar 2 - parImpar " << '\n' << '\n';
		cout << "(10) Quit" << '\n' << '\n';
		cout << "Your option is : ";
		cin >> menuChoice;

		//Menu
		switch (menuChoice)
		{
		case 1://   CASE 1
		{
			cout << "Please select the number of nodes you want to add: ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cout << "The element you want to insert is : ";
				cin >> x;
				cout << '\n';
				addFirst(head, last, x);
				cout << "The list looks like this: ";
				print(head);
				cout << '\n';
			}
			deleteAll(head);
			break;
		}
		case 2://   CASE 2
		{
			cout << "Please select the number of nodes you want to add: ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cout << "The element you want to insert is : ";
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like this: ";
				print(head);
				cout << '\n';
			}
			deleteAll(head);
			break;
		}
		case 3: //   CASE 3
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list.Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cout << "The element you want to insert is : ";
				cin >> x;
				cout << '\n';
				cout << "The position you want the element to be is : ";
				cin >> k;
				if (k > n || k < 1)
				{
					cout << "Invalid position" << '\n';
					break;
				}
				addMid(head, last, x, k);
				kk++;
				cout << "The list looks like this: ";
				print(head);
				cout << '\n';
			}
			deleteAll(head);
			break;
		}
		case 4://   CASE 4
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like this: ";
				print(head);
				cout << '\n';

			}
			cout << "The value/data of the node you are searching : ";
			cin >> val;
			searchVal(head, val);
			deleteAll(head);
			break;
		}
		case 5://   CASE 5
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like this: ";
				print(head);
				cout << '\n';

			}
			cout << "The position you want to check if there is any node there : ";
			cin >> poz;
			searchPoz(head, poz);
			deleteAll(head);
			break;
		}
		case 6://   CASE 6
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like his: ";
				print(head);
				cout << '\n';
			}
			cout << "Enter the value/data of the node you want to remove : ";
			cin >> delVal;
			deleteVal(head, last, delVal);
			cout << "The list looks like his: " << '\n';
			print(head);
			deleteAll(head);
			break;
		}
		case 7://   CASE 7
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like his: ";
				print(head);
				cout << '\n';

			}
			cout << "Enter the position of the node you want to remove : ";
			cin >> delPoz;
			if (delPoz > n || delPoz < 1)
			{
				cout << "Pozitie invalida" << '\n';
				break;
			}
			deletePoz(head, delPoz);
			cout << "The list looks like his: " << '\n';
			print(head);
			deleteAll(head);
			break;
		}
		case 8://   CASE 8
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like his: ";
				print(head);
				cout << '\n';
			}
			deleteAll(head);
			cout << "The list looks like this after the removal of all nodes : ";
			print(head);
			cout << '\n';
			cout << "Now, as you can see, the list is empty.";
			break;
		}
		case 10:
		{
			cout << "In order to demonstrate the functionability of this function, please select the number of nodes you want to insert in the beginning.\n";
			cout << "The nodes will be inserted each at the end of the list. Insert the number of nodes : ";
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> x;
				cout << '\n';
				addLast(head, last, x);
				cout << "The list looks like his: ";
				print(head);
				cout << '\n';
			}
			//print(head);
			parImpar(head, nrPare, ma, impare);
			cout << "Numarul de numere pare este "<<nrPare << ' ' <<"Iar media aritmetica a celor impare este "<< ma << '\n';
		}
		case 9://   CASE 9 QUIT
		{
			repeat = false;
		}
		}
	}
	cout << endl;
	system("pause");
}

#endif