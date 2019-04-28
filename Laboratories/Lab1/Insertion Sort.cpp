#include "stdafx.h"
#if 0
int main()
{
	int n, i, v[20], imin, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> v[i];

	for (i = 1; i <= n; i++)
	{
		imin = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > imin)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = imin;
	}
	for (i = 1; i <= n; i++)
		cout << v[i] << ' ';
	system("pause");
}
#endif