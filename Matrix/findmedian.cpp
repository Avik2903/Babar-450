#include<bits/stdc++.h>
using namespace std;
void mediana(int arr[9])
{
    int mid=(9)/2;
    cout<<arr[mid];
}
int main() {
    int A[3][3];
    int arr[9];
    int c=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
            arr[c++]=A[i][j];
        }
    }
    sort(arr,arr+9);
    mediana(arr);
    return 0;
}