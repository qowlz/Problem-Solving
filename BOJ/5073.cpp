// 삼각형과 세 변
// https://www.acmicpc.net/problem/5073

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true)
    {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        int sum = a + b + c;
        if (sum == 0) break;

        string ans = "";
        int longest = max(a, max(b, c));
        if (longest >= sum - longest) ans += "Invalid";
        else if (a == b && a == c && b == c) ans += "Equilateral";
        else if (a != b && a != c && b != c) ans += "Scalene";
        else ans += "Isosceles";
        cout << ans << '\n';
    }
}
