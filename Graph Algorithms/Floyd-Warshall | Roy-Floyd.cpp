#include"libraries.h"

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

int m[10001][10001], n;

void roy()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[i][j] > m[i][k] + m[k][j] || (m[i][j] == 0 && i != j) && m[i][j] && m[j][k])
					m[i][j] = m[i][k] + m[k][j];
			}
		}
	}
}

int main()
{
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> m[i][j];

	roy();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << m[i][j] << ' ';
		fout << endl;
	}
	system("pause");
}
