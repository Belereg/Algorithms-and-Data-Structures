#include "stdafx.h"

void citireMatrice(int a[100][100],int m)
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
}
void checkAndChange(int a[100][100], int i, int j, int changer)
{
	a[i][j] = changer;
	if (a[i - 1][j] == 1)
		checkAndChange(a, i - 1, j, changer);
	if (a[i + 1][j] == 1)
		checkAndChange(a, i + 1, j, changer);
	if (a[i][j + 1] == 1)
		checkAndChange(a, i, j + 1, changer);
	if (a[i][j - 1] == 1)
		checkAndChange(a, i, j - 1, changer);
}

int main()
{
	int n, m, i, j, changer = 1, a[100][100] = { 0 };
	cout << "cate linii si coloane vrei sa aiba matricea? \n";

	cin >> m;
	citireMatrice(a,m);

	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			if (a[i][j] == 1)
			{
				++changer;
				checkAndChange(a, i, j, changer);
			}

	cout << '\n';

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
			if (a[i][j])
				cout << a[i][j] << ' ';
			else
				cout << ' ';

		cout << '\n';
	}

	system("pause");
}
