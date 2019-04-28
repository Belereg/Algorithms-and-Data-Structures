#include "stdafx.h"
#if 0
int main() {
	int n, v[10], i, j, imin;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> v[i];

	for (i = 0; i < n - 1; i++)
	{
		imin = i; 
			for (j = i + 1; j < n; j++)
				if (v[j] < v[imin])
					imin = j;
		swap(v[imin], v[i]);

	}
	for (i = 0; i < n; i++)
		cout << v[i] << ' ';
	system("pause");
}
#endif