// 셀프 넘버
// https://www.acmicpc.net/problem/4673
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 1; i <= 10000; i++)
    {
        bool found = false;
        for (int j = 1; j < i; j++)
        {
            int num = j;
            int sum = num;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }

            if (sum == i) {found = true; break; }
        }

        if (!found) cout << i << '\n';
    }
}
