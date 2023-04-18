// 별찍기-10
// https://www.acmicpc.net/problem/2447

#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> board;

void solve(pair<int, int> min, pair<int, int> max)
{
    int n = max.first - min.first + 1;
    if (n == 3)
    {
        board[min.first + 1][min.second + 1] = ' ';
        return;
    }

    // draw spaces
    int len = n / 3;
    for (int y = min.first + len; y < min.first + len * 2; y++)
        for (int x = min.second + len; x < min.second + len * 2; x++)
            board[y][x] = ' ';

    pair<int, int> nMins[] =
    {
        min, // top left
        make_pair(min.first, min.second + len), // top middle
        make_pair(min.first, min.second + len * 2), // top right
        make_pair(min.first + len, min.second), // middle left
        make_pair(min.first + len, min.second + len * 2), // middle right
        make_pair(min.first + len * 2, min.second), // bottom left
        make_pair(min.first + len * 2, min.second + len), // bottom middle
        make_pair(min.first + len * 2, min.second + len * 2), // bottom right
    };

    for (int i = 0; i < 8; i++)
    {
        auto nMin = nMins[i];
        auto nMax = make_pair(nMin.first + len - 1, nMin.second + len - 1);
        solve(nMin, nMax);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    board.assign(n, vector<char>(n, '*'));
    solve(make_pair(0, 0), make_pair(n -1, n -1));
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cout << board[y][x];
        cout << '\n';
    }
}
