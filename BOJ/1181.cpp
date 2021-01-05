#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) 
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	int n = 0;
	cin >> n;

	vector<string> sorted;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		sorted.push_back(input);
	}

	sort(sorted.begin(), sorted.end(), compare);

	for (int i = 0; i < sorted.size(); i++)
	{
		// Do not print same word
		if (i > 0 && sorted[i] == sorted[i - 1]) continue;

		cout << sorted[i] << endl;
	}

	return 0;
}

