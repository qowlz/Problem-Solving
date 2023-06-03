// [SILVER 1]나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 1,  2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int N;

int bfs(const pair<int, int> start, const pair<int, int>& target)
{
    vector<vector<bool>> check(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push(start);
    check[start.first][start.second] = true;

    int ret = 0;
    while (!q.empty())
    {
        auto loop = q.size();
        while (loop--)
        {
            auto current = q.front();
            q.pop();

            if (current == target) return ret;

            for (int i = 0; i < 8; i++)
            {
                int nx = current.first + dx[i];
                int ny = current.second + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (check[nx][ny]) continue;

                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }

        ret++;
    }

    return -1;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> N;

        pair<int, int> start;
        cin >> start.first >> start.second;

        pair<int, int> target;
        cin >> target.first >> target.second;

        cout << bfs(start, target) << '\n';
    }

    return 0;
}
