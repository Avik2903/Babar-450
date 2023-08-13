#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==0)
            b=1;
        }
    }
    if(b==1)
    cout<<"true";
    else
    cout<<"false";
    return 0;
}