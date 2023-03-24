#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    cin >> M;
    vector<int> fNums(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> fNums[i];
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < fNums.size(); i++)
    {
        int target = fNums[i];
        int left = 0;
        int right = nums.size() - 1;
        bool match = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
            {
                match = true;
                break;
            }
            else if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
        }

        cout << (int)match << " ";
    }
}
