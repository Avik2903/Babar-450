#include <bits/stdc++.h>
using namespace std;
int  main()
{
    int n,sum,c=0;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            {
                cout<<a[i]<<" "<<a[j]<<endl;  //print all count pairs
                c++;   ///count of pairs
            }
        }
    }
    cout<<c;
    return 0;
}