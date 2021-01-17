#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_EDGE_SIZE 100000
using namespace std;

class Edge 
{
public:
	int node1, node2 = 0;
	int weight;

	Edge(int node1, int node2, int weight)
	{
		this->node1 = node1;
		this->node2 = node2;
		this->weight = weight;
	}

	bool operator<(Edge e) const 
	{
		return this->weight < e.weight;
	}
};

/// Get Parent Node
int getParent(int arr[], int x) 
{
	if (arr[x] == x) return x;

	return getParent(arr, arr[x]);
}

/// Kruskal Algorithm Implementation
int main()
{
	int v, e = 0;
	cin >> v >> e;

	vector<Edge> edges;
	for (int i = 0; i < e; i++)
	{
		int n1, n2, w = 0;
		cin >> n1 >> n2 >> w;
		edges.push_back(Edge(n1, n2, w));
	}

	sort(edges.begin(), edges.end());
	
	// array init
	int cycles[MAX_EDGE_SIZE + 1] = { 0 };
	for (int i = 0; i < sizeof(cycles) / sizeof(int); i++) 
	{
		cycles[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < edges.size(); ++i) 
	{
		Edge edge = edges[i];
		int node1Parent = getParent(cycles, edge.node1);
		int node2Parent = getParent(cycles, edge.node2);

		// check cycle
		if (node1Parent != node2Parent) 
		{
			// parent node setting
			if (node1Parent < node2Parent)
				cycles[node2Parent] = node1Parent;
			else
				cycles[node1Parent] = node2Parent;

			sum += edge.weight;
		}
	}

	cout << sum << endl;
}

