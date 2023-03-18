#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    a -= 1; b -= 1;
    while(n)
    {
        a /= 2; b /= 2; 
        if (a == b) break;    
        
        n /= 2;
        answer++;
    }

    return answer;
}
