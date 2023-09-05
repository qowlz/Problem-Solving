// [Bronze 5] 대소문자 바꾸기
// https://www.acmicpc.net/problem/2744
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str = "";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i])) str[i] = tolower(str[i]);
        else str[i] = toupper(str[i]);
    }

    cout << str << '\n';

    return 0;
}
