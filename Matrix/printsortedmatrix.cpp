#include<bits/stdc++.h>
using namespace std;
int main() {
    int A[4][4];
    int arr[16];
    int c=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> A[i][j];
            arr[c++]=A[i][j];
        }
    }
    sort(arr,arr+16);
    for(int i=0;i<16;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}