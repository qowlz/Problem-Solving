// [PLATINUM 5] Strongly Connected Component
// SCC 알고리즘 구현 문제
// 사실상 거의 블로그의 설명과 코드를 참고해서 푼거라 스스로의 힘으로 풀었다는 생각은 크게 안듬
// 그래도 직접 구현해보니 글만 봤을때 보다는 이해가 잘되는듯함. 하지만 아직도 교차간선에 대해서는 쪼오오끔 헷갈리는듯한? 느낌
// 추후에는 이 로직과 비슷한 BCC를 구현해보기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> E;
vector<int> DFSN;
vector<int> STK;
vector<bool> FINISHED;
vector<vector<int>> ANSWER;
int COUNTER = 0;

int dfs(int idx)
{
    DFSN[idx] = ++COUNTER;
    STK.push_back(idx);

    int result = DFSN[idx];
    for (int adj : E[idx])
    {
        if (DFSN[adj] == 0) result = min(result, dfs(adj));
        else if (!FINISHED[adj]) result = min(result, DFSN[adj]);
    }

    if (result == DFSN[idx])
    {
        vector<int> scc;
        while(true)
        {
            int pop = STK.back();
            STK.pop_back();

            scc.push_back(pop);
            FINISHED[pop] = true;
            if (pop == idx) break;
        }
        sort(scc.begin(), scc.end());
        ANSWER.push_back(scc);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    E.assign(v, vector<int>(0));
    DFSN.assign(v, 0);
    FINISHED.assign(v, false);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < v; i++)
        if (DFSN[i] == 0) dfs(i);

    cout << ANSWER.size() << '\n';

    sort(ANSWER.begin(), ANSWER.end());
    for (auto& list : ANSWER)
    {
        for (int item : list)
        {
            cout << item + 1 << ' ';
        }
        cout << "-1" << '\n';
    }

    return 0;
}
