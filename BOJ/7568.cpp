#include <iostream>
#include <algorithm>
#define MAX 200

int weight[MAX] = {};
int height[MAX] = {};
int result[MAX] = {};

using namespace std;

int main()
{
	fill_n(result, MAX, 1);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		cin >> height[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 자기 자신은 제외
			if (i == j) continue;
			
			if (weight[i] < weight[j] && height[i] < height[j])
				result[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	cout << endl;

	return 0;
}