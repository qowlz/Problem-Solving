#include <iostream>
#include <algorithm>
using namespace std;

int squareInt(int x)
{
    return x * x;
}

int getSqrDistance(int x1, int y1, int x2, int y2)
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
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = getSqrDistance(x1, y1, x2 , y2);
        if (x1 == x2 && y1 == y2 && r1 == r2) // 중심점이 같고 반지름이 같은 동심원의 경우
            cout << "-1\n";
        else if (squareInt(r1 + r2) == d || squareInt(abs(r2 - r1)) == d) // 한 점에서 만난 경우
            cout << "1\n";
        else if (squareInt(r1 + r2) > d && squareInt(abs(r2 - r1)) < d) // 두 점에서 만나는 경우
            cout << "2\n";
        else
            cout << "0\n";
    }

    return 0;
}
