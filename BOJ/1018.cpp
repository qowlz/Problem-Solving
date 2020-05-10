#include <iostream>
#include <algorithm>
#define MAX 2500
char board[MAX] = {};
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	char start = 'W';
	char other = 'B';
	int result = MAX;

	cin >> n >> m;

	for (int i = 0; i < n * m; i++) cin >> board[i];

	for (int h = 0; h < n; h++)
	{
		for (int w = 0; w < m; w++)
		{
			// 8X8 º¸µåÆÇÀ» ¸¸µé¼ö¾ø´Â ÁöÁ¡ÀÌ¸é °Ë»ç¾ÈÇÔ
			if (h + 8 > n || w + 8 > m) continue;

			int count = 0;
			for (int i = h; i < h + 8; i++)
			{
				for (int j = w; j < w + 8; j++)
				{
					// È¦Â¦ / Â¦È¦ ÀÏ¶§´Â other¶û ºñ±³
					if ((i % 2) ^ (j % 2))
					{
						if (board[i * m + j] != other) count++;
					}
					// È¦È¦/ Â¦Â¦ ÀÏ¶§´Â other¶û ºñ±³
					else
					{
						if (board[i * m + j] != start) count++;
					}
				}
			}

			result = min(result, count);
			result = min(result, 64 - count);
		}
	}

	cout << result << endl;

	return 0;
}