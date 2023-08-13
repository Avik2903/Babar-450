#include <bits/stdc++.h>
using namespace std;
int main(){
int n,i,j,x=0,y=0;
cin>>n;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n;i++)
{
    if(i%2==0)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]<0)
            {
                cout<<a[j]<<" ";
                a[j]=0;
                break;
            }
        }
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>0)
            {
                cout<<a[j]<<" ";
                a[j]=0;
                break;
            }
        }
    }
}
for(i=0;i<n;i++)
{
    if(a[i]!=0)
    cout<<a[i]<<" ";
}
    return 0;
}