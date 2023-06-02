// 포도주 시식
// https://www.acmicpc.net/problem/2156

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 3, 0);
    for (int i = 3; i < arr.size(); ++i)
        cin >> arr[i];


    vector<int> d(n + 3, 0);
    for (int i = 3; i < d.size(); i++)
    {
        int drink = max(d[i - 3] + arr[i - 1] + arr[i], d[i - 2] + arr[i]); // i번째 포도주를 마시는 경우 중 가장 큰 값
        d[i] = max(drink, d[i - 1]); // i번째 포도주를 마시지 않은 경우의 값과 i번째 포도주를 마신 경우의 값을 비교
    }

    cout << *d.rbegin() << '\n';

    return 0;
}
