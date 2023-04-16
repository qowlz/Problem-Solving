// 최댓값과 최솟값
// https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <set>
using namespace std;

string solution(string s) {
    int start = 0;
    set<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.insert(stoi(s.substr(start, i - start)));
            start = i + 1;
        }
    }
    st.insert(stoi(s.substr(start)));

    return to_string(*st.begin()) + " " + to_string(*st.rbegin());
}
