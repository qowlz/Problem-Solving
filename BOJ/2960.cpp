#include <iostream>
#define MAX_SIZE 1000
using namespace std;

int main()
{
	int n, k = 0;
	cin >> n >> k;
	
	int arr[MAX_SIZE] = { 0 };
	for (int i = 2; i <= MAX_SIZE; i++)
	{
		arr[i - 2] = i;
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) 
	{
		for (int j = i; j <= n; j += i) 
		{
			if (arr[j - 2] == 0) continue;

			if (++cnt >= k) 
			{
				cout << j << endl;
				return 0;
			}
			arr[j - 2] = 0;
		}
	}
}
