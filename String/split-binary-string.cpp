#include<bits/stdc++.h>
using namespace std;
int binary(string s)
{
    int n = s.length();
    int cnt=0,cnt1=0,cnt0=0;
    for(int i =0;i<n;i++)
    {
        if(s[i]=='0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
        if(cnt0==cnt1)
        {
            cnt++;
        }
    }
    if(cnt0!=cnt1)
    return -1;
    return cnt;
}
int main()
{
    string s;
    cin>>s;
    int a = binary(s);
    cout<<a;
    return 0;
}