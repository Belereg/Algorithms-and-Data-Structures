#include "stdafx.h"
#if 0
void afiseaza(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int randomNumberBetween(int firstnr, int endNumber)
{
	return firstnr + (rand() % (endNumber - firstnr + 1));
}

int partition(int arr[], int startIndex, int endIndex)
{
	int pivot = arr[endIndex];
	int i = startIndex;

	for (int j = startIndex; j < endIndex; j++) {
		if (arr[j] <= pivot) {
			swap(arr, i, j);
			i++;
		}
	}
	swap(arr, i, endIndex);
	return i;
}

int randomizedPartition(int arr[], int startIndex, int endIndex)
{
	int randomEndIndex = randomNumberBetween(startIndex, endIndex);
	swap(arr, endIndex, randomEndIndex);
	return partition(arr, startIndex, endIndex);
}

void randomizedQuickSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pivot = randomizedPartition(arr, startIndex, endIndex);
		randomizedQuickSort(arr, startIndex, pivot - 1);
		randomizedQuickSort(arr, pivot + 1, endIndex);
	}
}

int main()
{
	int n, arr[100]; 
	cout << "Introdu nr de elemente : ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	randomizedQuickSort(arr, 0, n - 1);
	cout << "Vectorul dupa sortar arata asa : ";
	afiseaza(arr, n);
	cout << endl;
	system("pause");
}

#endif
