#include<bits/stdc++.h>
using namespace std;
void dups(string s, int n)
{
    for(int i=0;i<n;i++)
    {int count=1;
        while(s[i]==s[i+1] && i<n-1 && s[i]!=' ')
        {
            count++;
            i++;
        }
        if(count>1)
        cout<<s[i]<<" , "<< count <<endl;
    }

}
int main()
{
    string s;
    getline(cin,s);
    int n=s.length();
    sort(s.begin(),s.end());
    dups(s,n);
}