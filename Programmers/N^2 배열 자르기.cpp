// N^2 배열 자르기
// https://school.programmers.co.kr/learn/courses/30/lessons/87390
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++)
    {
        answer.push_back(max(i / n, i % n) + 1);
    }
    
    return answer;
}
