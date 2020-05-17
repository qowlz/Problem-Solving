#include <iostream>
#define CARD_MAX 100
#define SELECT_NUM 3
using namespace std;

int n, m;
int cards[CARD_MAX] = {};
int result = 0;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		cin >> cards[i];
	}

	for (int i = 0; i <= n - 3; i++) 
	{
		for (int j = i + 1; j <= n - 2; j++) 
		{
			for (int k = j + 1; k <= n - 1; k++) 
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= m && sum > result) 
				{
					result = sum;
				}
			}
		}
	}

	cout << result << endl;

	return 0;
}