#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={22, 14, 8, 17, 35, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int min=arr[0],max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout<<min<<" "<<max;
    return 0;
}