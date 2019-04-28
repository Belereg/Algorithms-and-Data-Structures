#include "stdafx.h"
#if 0
int a[101];

void merge(int low, int mid, int high)
{
	int h, i, j, b[101], k;
	h = low;
	i = low;
	j = mid + 1;

	while ((h <= mid) && (j <= high))
	{
		if (a[h] <= a[j])
		{
			b[i] = a[h];
			h++;
		}
		else
		{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > mid)
	{
		for (k = j; k <= high; k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
		a[k] = b[k];
}

void merge_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = low + (high - low) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main()
{
	int nr, i;
	cout << "Introdu nr de numere : \n";
	cin >> nr;
	for (i = 1; i <= nr; i++)
	{
		cout << "x = ";
		cin >> a[i];
	}
	merge_sort(1, nr);

	cout << "\nVectorul sortat arata asa : \n";

	for (i = 1; i <= nr; i++)
		cout << a[i] << "  ";
	cout << endl;
	system("pause");

}
#endif