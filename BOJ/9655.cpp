#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string last = "";
    string current = "SK";
    while (N)
    {
        if (N - 3 >= 0 && (N - 3 != 1 || N - 3 != 3))
            N -= 3;
        else
            N -= 1;

        last = current;
        current = current == "SK" ? "CY" : "SK";
    }

    cout << last << '\n';
}
