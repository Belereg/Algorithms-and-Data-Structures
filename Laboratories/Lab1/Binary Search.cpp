#include "stdafx.h"

int main() {
	int n, mijl, ld, ls, v[10], x, ok = 0;

	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> v[i];
	cin >> x;

	ls = 0;
	ld = n - 1;

	while (ls <= ld && ok != 1) {
		mijl = (ls + ld) / 2;
		if (v[mijl] == x) {
			cout << "DA";
			ok = 1;
		}
		if (v[mijl]>x)
			ld = mijl - 1;
		if (v[mijl]<x)
			ls = mijl + 1;
	}
	if (ok == 0)
		cout << "NU" << ' ';
	system("pause");
}
