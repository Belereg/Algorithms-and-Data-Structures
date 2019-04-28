#include "stdafx.h"
#if 0
ifstream fin("Graf neorientat2.txt");
int a[101][101], v[101], n;

void pb2(int ns)
{
	int i;
	
	v[ns] = 1;
	for (i = 1; i <= n; i++)
		if (a[ns][i] == 1)
			if (v[i] == 0)
			{
				cout << i << " ";
				pb2(i);
			}
}

int main()
{
	int x, y, i, nrc = 0;
	
	fin >> n;
	while (fin >> x >> y)
		a[x][y] = a[y][x] = 1;
	for (i = 1; i <= n; i++)
		if (v[i] == 0)
		{

			cout << "componenta conexa : "<<nrc <<" contine : "<< ": " << i << " ";
			pb2(i);
			nrc++;
			cout << endl;
		}
	cout << "nr de componente conexe : " << nrc << endl;
	system("pause");
}
#endif