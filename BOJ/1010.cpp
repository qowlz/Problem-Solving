// [SILVER 5]다리 놓기
// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> cache;

int solve(int w, int e)
{
    if (w == N) return 1;

    if (e >= M) return 0;

    if (cache[w][e] != -1) return cache[w][e];

    int ret = 0;
    for (int i = e; i < M; ++i)
    {
        ret += solve(w + 1, i + 1);
    }

    return cache[w][e] = ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;

        cache.assign(N, vector<int>(M, -1));
        cout << solve(0, 0) << '\n';
    }

    return 0;
}
