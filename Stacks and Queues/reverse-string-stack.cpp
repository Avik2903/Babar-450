// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    stack<string> stc;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            stc.push(temp);
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    stc.push(temp);

    while (!stc.empty())
    {

        temp = stc.top();
        cout << temp << " ";
        stc.pop();
    }
    cout << endl;
}
int main()
{
    string s = "I Love To Code";
    reverse(s);
    return 0;
}
