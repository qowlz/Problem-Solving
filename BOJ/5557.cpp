// [GOLD 5] 1학년
// https://www.acmicpc.net/problem/5557
// 1시간 가량 생각을 해봤지만 아이디어가 떠오르지 않아 검색해본 문제
// 여전히 DP문제를 풀때 아이디어의 발상이 빈약한듯 하다.
// DP 문제 위주로 공부를 계속해보자

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];


    vector<vector<long long>> dp(n - 1, vector<long long>(21));

    dp[0][nums[0]] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            int add = j + nums[i];
            if (add >= 0 && add <= 20)
                dp[i][add] += dp[i - 1][j];

            int sub = j - nums[i];
            if (sub >= 0 && sub <= 20)
                dp[i][sub] += dp[i - 1][j];
        }
    }

    cout << dp[n - 2][nums[n - 1]] << '\n';

    return 0;
}
