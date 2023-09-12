// [BRONZE 3] 공 넣기
// https://www.acmicpc.net/problem/10810
// 단순하게 구현하면 되는 시뮬레이션 문제
// 연산량을 줄이는 방법으론 동일한 범위 내에 공을 넣는 후속 명령이 들어왔을 경우, 앞의 명령어를 지워주는 방법이 있을거같음.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> baskets(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = a - 1; j <= b - 1; j++)
            baskets[j] = c;
    }

    for (int i = 0; i < baskets.size(); i++)
        cout << baskets[i] << ' ';

    return 0;
}
