#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	int num = 666;
	int order = 0;
	while (true) 
	{
		int copy = num;
		int matchCnt = 0;
		while (copy != 0) 
		{
			if (copy % 10 == 6) 
			{
				if (++matchCnt == 3) break;
			}
			else 
			{
				matchCnt = 0;
			}

			copy /= 10;
		}

		if (matchCnt == 3) order++;

		if (order == N) break;

		num++;
	}

	cout << num << endl;

	return 0;
}