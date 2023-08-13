#include<bits/stdc++.h>
using namespace std;
void checkdups(string s1,string s2)
{
    string n = s1+s1;
    if(n.find(s2)!=-1)
        cout<<"Strings are in rotation";
    else if(s1.length()!=s2.length() || n.find(s2)==-1)
    cout<<"String are not in rotation";
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    checkdups(s1,s2);
    return 0;
}