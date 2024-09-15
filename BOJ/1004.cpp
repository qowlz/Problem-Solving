#include <iostream>
using namespace std;

int squareInt(int x)
{
    return x * x;
}

int getSqrDist(int x1, int y1, int x2, int y2)
{
    int xDiff = abs(x2 - x1);
    int yDiff = abs(y2 - y1);

    return squareInt(xDiff) + squareInt(yDiff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sDepth = 0, eDepth = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            int rr = squareInt(r);
            int sDist = getSqrDist(x1, y1, cx, cy);
            int eDist = getSqrDist(x2, y2, cx, cy);
            if (sDist <= rr && eDist <= rr) continue; // 출발점과 종점을 포함하고있는 원은 카운팅해줄 필요 X

            if (sDist <= rr) sDepth++;
            if (eDist <= rr) eDepth++;
        }

        cout << sDepth + eDepth << '\n';
    }
}
