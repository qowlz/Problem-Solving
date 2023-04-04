#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0)
    {
        if (n % 3 == 0) 
            answer += '4';
        else
            answer += (n % 3) + '0';
        
        n = (n % 3) == 0 ? n / 3 - 1 : n / 3;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}
