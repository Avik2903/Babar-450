#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int aa=0;
    int Smax=0;
    for(int i=0;i<n;i++)
    {
        aa+=a[i];
        if(aa<0)
        {
            aa=0;
        }
        Smax=max(Smax,aa);
    }
    cout<<Smax;
    return 0;
}