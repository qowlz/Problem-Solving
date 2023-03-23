#include <string>
#include <vector>
using namespace std;
int answer = 0;
int T = 0;

void dfs(const vector<int>& numbers, int depth, int sum)
{
    if (depth == numbers.size())
    {
        if (sum == T) answer++;
        return;
    }
    
    dfs(numbers, depth + 1, sum + numbers[depth]);
    dfs(numbers, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    T = target;
    dfs(numbers, 0, 0);
    
    return answer;
}
