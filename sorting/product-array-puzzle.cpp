#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = { 1, 2, 1, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int p=1;
    for(int i=0;i<n;i++)
    {
        p*=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<p*pow(arr[i],-1)<<" ";
    }
    return 0;
}
