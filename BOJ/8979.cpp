// 올림픽
// https://www.acmicpc.net/problem/8979

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country
{
    int id;
    int gold;
    int silver;
    int bronze;

    bool operator < (const Country& c) const
    {
        if (gold == c.gold)
        {
            if (silver == c.silver)
                return bronze > c.bronze;
            else
                return silver > c.silver;
        }

        return gold > c.gold;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<Country> countries(n);
    for (int i = 0; i < n; i++)
    {
        int c, g, s, b;
        cin >> c >> g >> s >> b;
        countries[c - 1] = Country {c, g, s, b};
    }

    sort(countries.begin(), countries.end());

    int rank = 1;
    Country prevC {-1, -1, -1, -1};
    for (int i = 0; i < countries.size(); i++)
    {
        auto curC = countries[i];
        if (prevC.id >= 0 && (prevC.gold != curC.gold || prevC.silver != curC.silver || prevC.bronze != curC.bronze))
            rank = i + 1;

        if (curC.id == k)
        {
            cout << rank << '\n';
            break;
        }
        else
            prevC = countries[i];
    }

    return 0;
}
