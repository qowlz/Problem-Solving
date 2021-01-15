#include <stdio.h>
#include <queue>
#include <vector>
#define INF 9999999
#define MAX_VERTICES 20000
using namespace std;

struct cmp
{
	bool operator()(pair<int, int>lhs, pair<int, int> rhs) 
	{
		return lhs.second > rhs.second;
	}
};

vector<pair<int, int>> vertices[MAX_VERTICES + 1];

int d[MAX_VERTICES + 1];


void dijkstra(int start) 
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	d[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) 
	{
		int current = pq.top().first;
		int dist = pq.top().second;
		pq.pop();

		if (d[current] < dist) continue;

		for (int i = 0; i < vertices[current].size(); i++) 
		{
			auto p = vertices[current][i];
			int next = p.first;
			int newDist = dist + p.second;

			if (newDist < d[next]) 
			{
				d[next] = newDist;
				pq.push({ next, newDist });
			}
		}
	}
}


int main()
{
	int v, e = 0;
	for (int i = 1; i <= MAX_VERTICES; i++)
		d[i] = INF;

	scanf("%d %d", &v, &e);

	int start = 0;
	scanf("%d", &start);

	for (int i = 0; i < e; i++) 
	{
		int u, v, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		auto p = make_pair(v, w);
		vertices[u].push_back(p);
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++) 
	{
		if (d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
	
	return 0;
}
