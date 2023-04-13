#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
int count = 0;
char vowels[] = {'A', 'E', 'I', 'O', 'U'};

void dfs(const string &word, string str)
{   
    if (str == word) answer = count;
    if (str.length() >= 5) return;
    
    for (int i = 0; i < 5; i++)
    {
        count++;
        dfs(word, str + vowels[i]);
    }
}

int solution(string word) {
    dfs(word, "");
    return answer;
}
