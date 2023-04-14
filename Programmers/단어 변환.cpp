#include <string>
#include <vector>

using namespace std;

int dfs(string current, string &target, vector<string> &words, int depth, vector<bool> &visit)
{
    if (current == target) return depth;
    
    int result = 51;
    for (int i = 0; i < words.size(); i++)
    {
        if (visit[i]) continue;
        
        auto word = words[i];
        int diff = 0;
        // 두 단어의 길이가 다르면 seg fault 날듯?
        for (int it = 0; it < word.length(); it++)
        {
            if (current[it] != word[it]) diff++;
        }
        if (diff >= 2) continue;
        
        visit[i] = true;
        result = min(result, dfs(word, target, words, depth + 1, visit));
        visit[i] = false;
    }
    
    return result;
}


int solution(string begin, string target, vector<string> words) {
    vector<bool> visit(words.size(), false);
    int answer = dfs(begin, target, words, 0, visit);
    return answer > 50 ? 0 : answer;
}
