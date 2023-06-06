//  쉬운 계단 수
// https://www.acmicpc.net/problem/10844

#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> cache;

long long solve(int n, int num)
{
    if (num < 0 || num > 9) return 0;

    if (n == 1) return 1;

    if (cache[num][n] != -1) return cache[num][n];

    return cache[num][n] = (solve(n - 1, num - 1) + solve(n - 1, num + 1) % 1000000000);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cache.assign(10, vector<long long>(n + 1, -1));
    long long answer = 0;
    for (int i = 1; i <= 9; i++)
        answer += solve(n, i);

    cout << answer % 1000000000 << '\n';

    return 0;
}
