#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={ 5, 5, 10, 100, 10, 5 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    int a=arr[0];
    int b=0;
    int c;
    for(int i=1;i<n;i++)
    {
        c=max(a,b);
        a=b+arr[i];
        b=c;
    }
    cout<<max(a,b);
    return 0;
}