#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int s=0,e=n-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(s<e)
        {
            int temp=a[s];
            a[s]=a[e];
            a[e]=temp;
            s++;e--;
        }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}