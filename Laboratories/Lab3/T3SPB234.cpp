#include "stdafx.h"

struct polP {
	int grP, coefP;
	polP *nextP;
};

struct polQ {
	int grQ, coefQ;
	polQ *nextQ;
};

void makeListP(polP *&headP, polP *&lastP, int grad, int coeficient)
{
	//functia adauga noduri la sfarsitul listei
	polP *p = new polP;
	p->grP = grad;
	p->coefP = coeficient;
	p->nextP = NULL;
	if (headP == NULL)
	{
		headP = p;
		lastP = p;
	}
	else
	{
		lastP->nextP = p;
		lastP = p;
	}

}

void makeListQ(polQ *&headQ, polQ *&lastQ, int grad, int coeficient)
{
	//functia adauga noduri la sfarsitul listei
	polQ *p = new polQ;
	p->grQ = grad;
	p->coefQ = coeficient;
	p->nextQ = NULL;
	if (headQ == NULL)
	{
		headQ = p;
		lastQ = p;
	}
	else
	{
		lastQ->nextQ = p;
		lastQ = p;
	}
}

void inmultirePol(polP *&headP, int a)
{
	polP *p = headP;
	while (p != NULL)
	{
		p->coefP *= a;
		p = p->nextP;
	}

}

int PxCalcul(polP *&headP, int &px)
{
	cout << "x a intrat in functie ca px cu valoarea" << px << endl;
	int sx = 0;
	polP *p = headP;
	while (p != NULL)
	{
		sx = sx + p->coefP*pow(px, p->grP);
		p = p->nextP;
	}
	return sx;
}

void printP(polP *&headP)
{
	polP *p = headP;
	while (p != NULL)
	{
		cout << p->coefP << "*X^" << p->grP << ' ';
		p = p->nextP;
	}
	cout << '\n';
}

void printQ(polQ *&headQ)
{
	polQ *p = headQ;
	while (p != NULL)
	{
		cout << p->coefQ << "*X^" << p->grQ << ' ';
		p = p->nextQ;
	}
	cout << '\n';
}

long long prodScal(polP *&headP, polQ *&headQ)
{
	long long prodscal = 0;
	polP *p = headP;
	polQ *q = headQ;
	do
	{
		if (p->grP < q->grQ)
			p = p->nextP;
		if (q->grQ < p->grP)
			q = q->nextQ;
		if (p->grP == q->grQ)
		{
			prodscal = prodscal + p->coefP * q->coefQ;
			p = p->nextP;
			q = q->nextQ;
		}
	} while (p != NULL && q != NULL);
	return prodscal;
}

int main()
{
	polP *headP = NULL;
	polP *lastP = NULL;
	polQ *headQ = NULL;
	polQ *lastQ = NULL;

	bool repeat = true;
	int n, coeficient, grad, i, a, menuChoise, x;

	cout << "Pentru inceput,trebuie sa iti setezi cele doua polinoame P si Q.";
	cout << "Ce grad sa aiba polinomul P? ";
	cin >> n;
	cout << '\n';
	for (i = 1; i <= n + 1; i++)
	{
		cin >> grad;
		if (grad != 0)
			cin >> coeficient;
		else
		{
			cin >> coeficient;
			makeListP(headP, lastP, grad, coeficient);
			break;
		}
		makeListP(headP, lastP, grad, coeficient);
	}
	
	printP(headP);
	cout << "\n Acum trebuie sa setezi polinomul Q: \n Ce grad sa aiba polinomul Q? \n";
	cin >> n;
	for (i = 1; i <= n + 1; i++)
	{
		cin >> grad;
		if (grad != 0)
			cin >> coeficient;
		else
		{
			cin >> coeficient;
			makeListQ(headQ, lastQ, grad, coeficient);
			break;
		}
		makeListQ(headQ, lastQ, grad, coeficient);
	}
	printQ(headQ);
	cout << "\n ----------------------------------------------- \n";
	cout << "P(X)=";
	printP(headP);
	cout << '\n';
	cout << "Q(X)=";
	printQ(headQ);
	cout << '\n';

	while (repeat == true)
	{
		cout << "Acum alege una dintre optiunile \n";
		cout << "(2) Inmulteste polinomul P cu un scalar a \n";
		cout << "(3) Evalueaza polinomul P intr-un punct dat x \n";
		cout << "(4) Suma polinoamelor P si Q \n";
		cout << "(5) Produsul polinoamelor P si Q \n";
		cout << "(6) Quit \n";
		cin >> menuChoise;
		switch (menuChoise)
		{
		case 2:
		{

			cout << "introdu numarul cu care vrei sa fie inmultit polinomul P? ";
			cin >> a;
			inmultirePol(headP, a);
			cout << "\n polinomul arata asa: \n ";
			printP(headP);
			cout << '\n';
			break;

		}
		case 3:
		{
			cout << "In ce punct vrei sa evaluezi polinomul P? \n";
			cin >> x;
			cout << PxCalcul(headP, x);
			cout << '\n';
			break;
		}
		case 4:
		{
			polP *p = headP;
			polQ *q = headQ;
			if (p->grP > q->grQ)
				while (p->grP > q->grQ)
				{
					cout << p->grP << ' ' << p->coefP << '\n';
					p = p->nextP;
				}
			else if (p->grP < q->grQ)
				while (q->grQ > p->grP)
				{
					cout << q->grQ << ' ' << q->coefQ << '\n';
					q = q->nextQ;
				}
			while (p != NULL || q != NULL)
			{
				cout << q->grQ << ' ' << p->coefP + q->coefQ << '\n';
				p = p->nextP;
				q = q->nextQ;
			}
			cout << '\n';
			break;
		}
		case 5:
		{
			cout << "Produsul scalar P * Q = \n" << prodScal(headP, headQ);
			break;
		}
		case 6:
			repeat = false;
		}
	}
	cout << '\n';
	system("pause");
}
