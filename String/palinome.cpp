#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abba";
    int c=0;
    int len=s.length();
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if(s[i]==s[j])
        c++;
        else
        cout<<"No";
    }
    if(c==len/2)
    cout<<"Yes";
    return 0;
}