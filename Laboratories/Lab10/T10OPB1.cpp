#include "stdafx.h"
ifstream fin("Graf neorientat.txt");

int grad(int x, int n, int m[50][50])
{
	int xx = x - 1;
	int grad = 0;
	for (int j = 0; j < n; j++)
		if (m[xx][j] == 1)
			grad++;
	return  grad;
}

int nr_muchii(int n, int m[50][50])
{
	int nr_muchii = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (m[i][j] == 1)
				nr_muchii++;
	return nr_muchii;
}

void grad_max(int n, int m[50][50])
{
	int grad_maxim, maxx = 0, maxxx = 0;
	for (int i = 0; i < n; i++)
	{
		grad_maxim = 0;
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] == 1)
				grad_maxim++;
		}
		if (grad_maxim > maxx)
			maxx = grad_maxim;
	}

	for (int i = 0; i < n; i++)
	{
		grad_maxim = 0;
		for (int j = 0; j < n; j++)
			if (m[i][j] == 1)
				grad_maxim++;
		if (grad_maxim == maxx)
			cout << i << ' ';
	}
}

int main()
{
	int n, m[50][50] = { {0} }, nr_grad;
	fin >> n;
	cout << "nr de varfuri este " << n;
	cout << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> m[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << m[i][j] << ' ';
		cout << endl;
	}
	cout << "al cui grad vrei sa ii aflii rank ul? : ";
	cin >> nr_grad;
	if (nr_grad <0 || nr_grad >n)
	{
		cout << "varful nu exista\n";
		system("pause");
		exit(1);
	}

	int grad_x = grad(nr_grad, n, m);
	cout << grad_x << endl;

	cout << "numarul de muchii al grafului este : ";
	int nr_muchii_graf = nr_muchii(n, m);
	cout << nr_muchii_graf << endl;

	cout << "Gradul maxim din graf este : ";
	grad_max(n, m);

	system("pause");
}
