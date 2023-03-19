#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int loop = elements.size();
    set<int> s;
    for (int len= 1; len <= elements.size(); len++)
    {
        for (int start = 0; start < elements.size(); start++)
        {
            int sum = 0;
            for (int i = 0; i < len; i++)
            {
                sum += elements[(start + i) % elements.size()];
            }
            s.insert(sum);
        }
    }


    return s.size();
}
