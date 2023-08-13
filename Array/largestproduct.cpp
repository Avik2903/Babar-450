#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int mav=a[0];
    int miv=a[0];
    int map=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            swap(mav,miv);
        }
        mav=max(a[i],mav*a[i]);
        miv=min(a[i],miv*a[i]);
        map=max(mav,map);
    }
    cout<<map;
    return 0;
}