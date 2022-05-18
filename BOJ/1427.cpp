// BOJ 소트 인사이드(1427)
// 실제로 sort로 정렬하지 않고도 해결이 가능함
// 0~9범위의 숫자를 내림차순으로 정렬하기만 하면 되는거라서 각 숫자가 나온 횟수를 저장한다음에 9~0 순서대로 순회하며 횟수만큼 숫자를 출력해주면 더 빠르게 동작함

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	cin >> num;
	
	vector<int> nums;
	while (num)
	{
		nums.push_back(num % 10);
		num /= 10;
	}
	
	sort(nums.begin(), nums.end(), greater<int>());
	
	for (int i =0; i < nums.size(); i++)
		cout << nums[i];
}
