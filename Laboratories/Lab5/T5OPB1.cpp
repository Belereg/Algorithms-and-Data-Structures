#include "stdafx.h"

struct nod
{
	int data;
	nod *next;
};

struct queue
{
	nod *head;
	nod *last;
};


void push(int a, queue *coada)
{
	nod *p = new nod;
	p->data = a;
	p->next = NULL;
	if (coada->head == NULL)
	{
		coada->head = p;
		coada->last = p;
	}
	else
	{
		coada->last->next = p;
		coada->last = p;
	}
}

int pop(queue *coada)
{
	if (coada->head == NULL)
		return -1;
	else
	{
		nod *p = coada->head;
		coada->head = coada->head->next;
		p->next = NULL;
		return p->data;
	}

}

int peek(queue *coada)
{
	if (coada->head == NULL)
		return -1;
	return coada->head->data;
}

bool empty(queue *coada)
{
	if (coada->head == NULL)
		return 1;
	return 0;
}

void afiseaza(queue *&coada)
{
	nod *p = coada->head;

	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}

int search(int a, queue *&coada)
{
	nod *p = coada->head;
	int k = 0;
	while (p)
	{
		if (p->data == a)
			return k;
		else
			k++;
		p = p->next;
	}
	return -1;
}
int main()
{
	queue *coada = new queue;
	coada->head = NULL;
	coada->last = NULL;
	int n, x, i;
	cout << "Cate elemente sa aiba coada? :";
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cout << "element = ";
		cin >> x;
		cout << endl;
		push(x, coada);
	}
	
	afiseaza(coada);
	cout << "dam pop la :" << pop(coada) << endl;
	afiseaza(coada);
	cout << endl;
	cout << "peek : ";
	cout << peek(coada) << endl;
	afiseaza(coada);
	cout << endl << "acum verificam daca coada este vida sau nu :: 1=este vida, 0=nu este vida\nverificare este: ";
	cout << empty(coada) << endl;
	afiseaza(coada);
	cout << endl;
	int y;
	cout << "elementul pe care il cauti in coada este ";
	cin >> y;
	cout << search(y, coada);
	system("pause");
}
