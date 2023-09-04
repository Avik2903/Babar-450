#include<bits/stdc++.h>
using namespace std;
// void swap(char &a,char &b)   //my utility function swap
// {
//     char temp=a;
//     a=b;
//     b=temp;
// }
void permute(string s,int l,int r)
{
    if(l==r)
    cout<<s<<" ";
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);   //pre-built function swap
            permute(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}
int main() {
    string s;
    cin>>s;
    int n=s.size();
    permute(s,0,n-1);
    return 0;
}