#include "stdafx.h"

typedef struct
{
	int cheie;
	int info;
}coada;

void heapmax(coada v[], int n, int i)
{
	int maxi = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && v[l].cheie > v[maxi].cheie)
		maxi = l;

	if (r < n && v[r].cheie > v[maxi].cheie)
		maxi = r;
	if (maxi != i)
	{
		swap(v[i], v[maxi]);
		heapmax(v, n, maxi);
	}
}

void heapSortmax(coada v[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapmax(v, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(v[0], v[i]);
		heapmax(v, i, 0);
	}
}

void afisare(coada v[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << v[i].info << " ";
	cout << "\n";
}

void maxim(coada v[], int n)
{
	cout << v[n - 1].info << "\n";
}

void extract_max(coada v[], int &n)
{
	cout << v[n - 1].info << "\n";
	n--;
}

int main()
{
	int x, i, n;
	coada v[100];
	int menuchoice = -1;
	do {
		cout << "1) Inserati elemente \n";
		cout << "2) Afiseaza elementul maxim \n";
		cout << "3) Sterge elementul maxim si il afiseaza \n";
		cout << "4) Afisare totala \n";
		cout << "5) BYEEE \n";
		cin >> menuchoice;
		switch (menuchoice) {
		case 1: {
			cout << "Introdu cate elemente sa adaugi: ";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cout << "Valoare elementului si prioritatea \n";
				cin >> v[i].info >> v[i].cheie;
			}
			heapSortmax(v, n);
			break;
		}
		case 2:
		{
			cout << "Afiseaza elementul maxim \n";
			maxim(v, n);
			break;
		}
		case 3:
		{
			cout << "Elementul eliminat este : \n";
			extract_max(v, n);
			break;
		}
		case 4:
		{
			cout << "Afisarea totala a cozii este : \n";
			afisare(v, n);
			break;
		}
		case 5: {break; }
		default: {break; }
		}
	} while (menuchoice != 5);
	system("pause");
}
