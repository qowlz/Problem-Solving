#include <string>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int is = 0;
    int uni = 0;
    map<string, int> m;

    for (int i = 0; i < str1.length() - 1; i++)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;

        string str = ""; 
        str += tolower(str1[i]); str+= tolower(str1[i + 1]);

        m[str]++;
        uni++;
    }

    for (int i = 0; i < str2.length() - 1; i++)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;

        string str = ""; 
        str += tolower(str2[i]); str+= tolower(str2[i + 1]);

        if (m[str]) 
        {
            is++;
            m[str]--;
        }
        else uni++;
    }

    float j = is == 0 && uni == 0 ? 1 : is / (float)uni;
    return (int)(j * 65536);
}
