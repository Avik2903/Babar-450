#include<bits/stdc++.h>
using namespace std;
bool palin(string s)
{
    int n=s.size();
    int i=0,j=n-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void part(vector<vector<string>> &res,string s,int start,vector<string> &curr)
{
    if(start==s.size())
    {
        res.push_back(curr);
        return;
    }
    string t;
    for(int i=start;i<s.size();i++)
    {
        t.push_back(s[i]);
        if(palin(t))
        {
            curr.push_back(t);
            part(res,s,i+1,curr);
            curr.pop_back();
        }
    }
}
int main() {
vector<vector<string>> res;
string s;
cin>>s;
int start=0;
vector<string> curr;
part(res,s,start,curr);
for(auto x:res)
{
    for(auto it:x)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
return 0;
}