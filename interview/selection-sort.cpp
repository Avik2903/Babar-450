// Selection Sort	n^{2}	n^{2}	n^{2}	space = 1	stable = No
#include<bits/stdc++.h>
using namespace std;
void selection(int arr[5],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        swap(arr[min],arr[i]);
    }
}
int main()
{
    int arr[]={5,6,8,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

}
