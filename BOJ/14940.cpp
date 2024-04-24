// Created by: byunguk
// Created at: 2024/4/24 (수요일)
// BOJ Number: 14940
// https://boj.kr/14940

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<int>> answer(n, vector<int>(m, -1));
    visit[q.front().first][q.front().second] = true;
    answer[q.front().first][q.front().second] = 0;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visit[ny][nx] || !arr[ny][nx]) continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx] = true;
            answer[ny][nx] = answer[p.first][p.second] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!arr[i][j]) answer[i][j] = 0; // 갈 수 없었던 땅들은 0으로 바꿔줌

            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
