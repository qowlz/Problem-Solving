#include <stdio.h>
#define MAX_SIZE 10000
using namespace std;

// counting sort implementation
int main()
{
	int n = 0;
	scanf("%d\n", &n);

	int cnt[MAX_SIZE] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d\n", &input);
		cnt[input - 1]++;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
			printf("%d\n", i + 1);
	}
}
