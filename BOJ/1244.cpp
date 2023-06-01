// 스위치 켜고 끄기
// https://www.acmicpc.net/problem/1244

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> switchs(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> switchs[i];
    }

    int sn;
    cin >> sn;
    while (sn--)
    {
        int sex, num;
        cin >> sex >> num;

        if (sex == 1) // boy
        {
            int current = num - 1;
            while (current < n)
            {
                switchs[current] = switchs[current] ? 0 : 1;
                current += num;
            }
        }
        else // girl
        {
            int center = num - 1;
            switchs[center] = switchs[center] ? 0 : 1;

            int left = center - 1, right = center + 1;
            while (left >= 0 && right < n)
            {
                if (switchs[left] != switchs[right]) break;

                switchs[left] = switchs[left] ? 0 : 1;
                switchs[right] = switchs[right] ? 0 : 1;
                left -= 1;
                right += 1;
            }
        }
    }

    // print
    for (int i = 0; i < switchs.size(); ++i)
    {
        cout << switchs[i];
        if ((i + 1) % 20 == 0) cout << '\n';
        else cout << ' ';
    }

    return 0;
}
