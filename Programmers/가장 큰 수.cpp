#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), [](int first, int second) -> bool
    {
        string a = to_string(first) + to_string(second);
        string b = to_string(second) + to_string(first);
        
        return stoi(a) > stoi(b);
    });
    
    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);
    
    return answer[0] == '0' ? "0" : answer;
}
