#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int min=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            min=arr[i+1];
        }
    }
    cout<<max<<" "<<min;
    return 0;
}