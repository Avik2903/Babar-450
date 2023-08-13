#include<bits/stdc++.h>
using namespace std;
int pal(int N){
    string s= to_string(N);
    string s1=s;
    reverse(s.begin(),s.end());
    if(s==s1)
    return 1;
    else
    return 0;
}
int main()
{
    int n,count=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
    if(pal(a[i])==true)
    count=count+1;
    }
    if(count == n)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
