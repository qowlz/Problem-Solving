#include <iostream>
#include <vector>
using namespace std;

int k = 0;
vector<int> s;
vector<int> l;

void dfs(int node) 
{
	if (l.size() == 6) 
	{
		for (int i = 0; i < l.size(); i++) 
		{
			cout << l[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = node; i < k; i++) 
	{
		l.push_back(s[i]);
		dfs(i + 1);
		l.pop_back();
	}
}

int main()
{
	while (true)
	{
		cin >> k;

		if (k == 0) break;

		s.clear();
		for (int i = 0; i < k; i++)
		{
			int n = 0;
			cin >> n;
			s.push_back(n);
		}

		dfs(0);
		cout << endl;
	}

	return 0;
}
