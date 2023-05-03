// 숫자의 표현
// https://school.programmers.co.kr/learn/courses/30/lessons/12924
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int add = i;
        int sum = 0;
        while (sum <= n)
        {
            sum += add;
            add += 1;
            if (sum == n) answer++;
        }
    }
    return answer;
}
