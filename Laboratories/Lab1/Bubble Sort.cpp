#include "stdafx.h"

//BUBBLE SORT

int main() {
	int N;
	cin >> N;

	int v[100];
	int i;
	for (i = 1; i <= N; i++)
		cin >> v[i];

	int j;
	int sortat;
	do {
		sortat = 1;
		for (i = 1; i <= N - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = 0;
			}
		}
	} while (sortat == 0);

	for (i = 1; i <= N; i++)
		cout << v[i] << " ";

	system("pause");

}
