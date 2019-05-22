#include "libraries.h"

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

vector <int> v[50002];
int grad[50002];
int sol[50002];
int n, m;

int main()
{
	int i, ii, j, x, y, ind = 1;
	fin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		fin >> x >> y;
		v[y].push_back(x);
		grad[x]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (grad[i] == 0)
		{
			sol[ind] = i;
			ind++;
		}
	}
	for (ii = 1; ii < ind; ii++)
	{
		i = sol[ii];
		for (j = 0; j < v[i].size(); j++)
		{
			grad[v[i][j]]--;
			if (!grad[v[i][j]])
			{
				sol[ind] = v[i][j];
				ind++;
			}
		}
	}
	for (j = n; j >=1; j--)
		fout << sol[j] << ' ';
	system("pause");
}
