#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count(const vector<vector<bool>> &m, vector<vector<bool>> &visit,  int current, int cut)
{
    int sum = 1;
    for (int i = 0; i < m.size(); i++)
    {
        if (i == cut || !m[current][i] || visit[current][i]) continue;
        visit[current][i] = true;
        visit[i][current] = true;
        sum += count(m, visit, i, -1);
    }
    
    return sum;
}


int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> m(n, vector<bool>(n, false));
    for (int i = 0; i < wires.size(); i++)
    {
        m[wires[i][0] - 1][wires[i][1] - 1] = true;
        m[wires[i][1] - 1][wires[i][0] - 1] = true;
    }
    
    int answer = 100;
    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int sum = count(m, visit, wires[i][0] - 1, wires[i][1] - 1);
        answer = min(answer, abs((n - sum) - sum));
    }
    
    return answer;
}
