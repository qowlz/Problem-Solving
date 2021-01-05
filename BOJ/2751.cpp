#include <stdio.h>
#define MAX_SIZE 1000000
using namespace std;

int inputs[MAX_SIZE] = { 0 };
int sorted[MAX_SIZE] = { 0 };

void merge(int arr[], int r1, int middle, int r2) 
{
	int i = r1;
	int j = middle + 1;
	int k = r1;

	while (i <= middle && j <= r2) 
	{
		if (arr[i] < arr[j]) 
		{
			sorted[k++] = arr[i++];
		}
		else 
		{
			sorted[k++] = arr[j++];
		}
	}

	// remaining data copy
	if (i <= middle) 
	{
		for (int it = i; it <= middle; it++) 
		{
			sorted[k++] = arr[it];
		}
	}
	else 
	{
		for (int it = j; it <= r2; it++)
		{
			sorted[k++] = arr[it];
		}
	}

	// sorted result copy
	for (int it = r1; it <= r2; it++)
	{
		arr[it] = sorted[it];
	}
}

void mergeSort(int arr[], int r1, int r2) 
{
	if (r1 >= r2) return;

	int middle = (r1 + r2) / 2;
	mergeSort(arr, r1, middle);
	mergeSort(arr, middle + 1, r2);

	merge(arr, r1, middle, r2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	// Input Values
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &inputs[i]);
	}

	mergeSort(inputs, 0, n - 1);

	// print 
	for (int i = 0; i < n; i++)
		printf("%d\n", inputs[i]);
}

