#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int search = 0;
	int result = 1000000;

	while (true)
	{
		search++;

		int check = search;
		int compare = search;

		// TODO: while로 compare가 0이 될떄까지 나누는 식이 더 좋아보임
		for (int i = 1; i <= 6; i++)
		{
			compare += check % 10;
			check /= 10;
		}

		if (search > n)
		{
			break;
		}
		else if (compare == n && result > search)
		{
			result = search;
		}
	}

	result = result == 1000000 ? 0 : result;

	cout << result << endl;

	return 0;
}