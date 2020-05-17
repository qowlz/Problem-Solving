#include <iostream>
#include <cmath>
#define MAX 15
using namespace std;

int N = 0;
int answer = 0;
int columns[MAX] = {};

bool isValid(int check) 
{
	for (int i = 0; i < check; i++) 
	{
		// 수평선상에 위치한다면 유효하지않음.
		if (columns[i] == columns[check]) return false;
		
		// 사선이여도 유효하지않음.
		if (abs(columns[check] - columns[i]) == check - i) return false;
	}

	return true;
}

void dfs(int placed) 
{
	if (placed == N) { answer++; return; }
	else 
	{
		for (int i = 0; i < N; i++) 
		{
			columns[placed] = i;
			if (isValid(placed)) 
			{
				dfs(placed + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	dfs(0);

	cout << answer << endl;

	return 0;
}