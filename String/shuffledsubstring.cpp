#include <bits/stdc++.h>
using namespace std;
bool shuffled(string s1, string s2)
{
    int a = s1.length();
    int b = s2.length();
    if (a > b)
    {
        return false;
    }
    else
    {
        sort(s1.begin(),s1.end());
        for (int i = 0; i < b; i++)
        {
            if (i + a - 1 >= b)
                return false;
            string s = "";
            for (int j = 0; j < a; j++)
                s.push_back(s2[i + j]);
            sort(s.begin(), s.end());
            if (s1 == s)
                return true;
        }
    }
    return false;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool a = shuffled(s1, s2);
    if (a)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}