#include <iostream>
#define MAX_SIZE 3
using namespace std;

int main()
{
	int n = MAX_SIZE;
	int arr[MAX_SIZE] = {0};

	// Input Values
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
	}

	// Bubble Sort
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				// swap
				arr[j + 1] += arr[j];
				arr[j] = arr[j + 1] - arr[j];
				arr[j + 1] -= arr[j];
			}
		}
	}

	// print 
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

