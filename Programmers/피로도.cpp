#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> p;
    for (int i = 0; i < dungeons.size(); i++)
        p.push_back(i);
    
    do
    {
        int fatigue = k;
        int sum = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (fatigue < dungeons[p[i]][0]) break;
            fatigue -= dungeons[p[i]][1];
            sum++;
        }
        answer = max(answer, sum);
        
    } while (next_permutation(p.begin(), p.end()));

    return answer;
}
