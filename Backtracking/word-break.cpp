#include<bits/stdc++.h>
using namespace std;
int dict(string &word)
{
    string d[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(d)/sizeof(d[0]);
    for (int i = 0; i < n; i++)
        if (d[i].compare(word) == 0)
            return true;
    return false;
}
void wordbreak(string str,int n,string result);
void wordBreak(string str)
{
    wordbreak(str, str.size(), "");
}
void wordbreak(string str,int n,string result)
{
    for (int i=1; i<=n; i++)
    {
        string prefix = str.substr(0, i);
        if (dict(prefix))
        {
            if (i == n)
            {
                result += prefix;
                cout << result << endl;
                return;
            }
            wordbreak(str.substr(i, n-i), n-i,result + prefix + " ");
        }
    }     
}
int main()
{
    wordBreak("iloveicecream");
    return 0;
}