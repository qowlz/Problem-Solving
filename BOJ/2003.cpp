// 수들의 합 2
// https://www.acmicpc.net/problem/2003
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N, M;
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    nums.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += nums[j];
            if (sum == M) answer++;
        }
    }

    cout << answer << '\n';
}
