#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int w = 1; w <= yellow; w++)
    {
        int h = yellow / w;
        if ((w + 2) * 2 + h * 2 == brown && w >= h)
        {
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }
    
    return answer;
}
