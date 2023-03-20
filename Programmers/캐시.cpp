#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    queue<string> cache;
    for (int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        for_each(city.begin(), city.end(), [](char & c) {
            c = ::tolower(c);
        });
        
        // 도시명 찾기
        int found = -1;
        vector<string> temp;
        while (!cache.empty())
        {
            if (city == cache.front())
                found = temp.size();
            
            temp.push_back(cache.front());
            cache.pop();
        }
        
        // 다시 캐시 채워주기
        for (int j = 0; j < temp.size(); j++)
        {
            if (found == j) continue;
            
            cache.push(temp[j]);
        }
        
        if (found >= 0)
        {
            cache.push(temp[found]);
            answer += 1;
        }
        else
        {
            if (cacheSize > 0 && cache.size() == cacheSize) cache.pop();
            if (cacheSize > 0) cache.push(city);
            answer += 5;
        }
    }
    
    return answer;
}
