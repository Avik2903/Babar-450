#include <bits/stdc++.h>
using namespace std;
bool pdchecker(string str)
{
    string s = str;
    reverse(s.begin(), s.end());
    if (s == str)
        return 1;
    return 0;
}
string pdadder(string str)
{
    string s = str;
    reverse(s.begin(), s.end());
    for (int i = 1; i < s.length(); i++)
    {
        string sub = s.substr(i, s.length());
        if (pdchecker(str + sub))
        {
            return sub;
        }

    }
    return "NULL";
}
int main()
{
    string str = "appl";
    cout << pdadder(str) << endl;
    return 0;
}