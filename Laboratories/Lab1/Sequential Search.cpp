#include "stdafx.h"
#if 0
int main() {

	int i, v[10], x, n, ok = 0;
	cin >> n;
	for (i = 0; i<n; i++)
		cin >> v[i];
	cin >> x;
	i = 0;
	while (i<n && ok == 0) {
		if (v[i] == x)
			ok = 1;
		i++;
	}
	if (ok == 1)
		cout << "DA";
	else cout << "NU";

	system("pause");
}
#endif
