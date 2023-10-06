#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i==pow(2,j))
            {
                ans++;
            }
        }
    }
    cout<<ans;
return 0;
}