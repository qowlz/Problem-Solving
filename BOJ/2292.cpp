#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int start = 1;
	int count = 0;
	int unit = 6;
	int compare = start;

	while (n > compare) 
	{
		compare += unit * ++count;
	}

	int result = start + count;
	cout << result;

	return 0;
}
