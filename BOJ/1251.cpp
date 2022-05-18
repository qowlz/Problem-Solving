#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string word;
	cin >> word;
	
	string shortest = "";
	for (int i = 0; i < word.length() - 2; i++)
	{
		for (int j = i + 2; j < word.length(); j++)
		{
			string comp = "";
			int start[3] = {i, j - 1, static_cast<int>(word.length() - 1)};
			int end[3] = {0, i + 1, j};
			for (int it = 0; it < 3; it++)
				for (int it2 = start[it]; it2 >= end[it]; it2--)
					comp += word[it2];
			
			if (shortest.empty() || shortest > comp)
				shortest = comp;
		}
	}
		
	cout << shortest << '\n';
}
