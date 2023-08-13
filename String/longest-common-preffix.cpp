#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j,res=0;
    string arr[] = {"geekos", 
                    "geekoer", 
                    "geeks",
                    "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x[n];
    for (i = 0; i < n; i++)
    {
        x[i] = arr[i].size();
    }
    sort(x, x + n);
    int len = x[0];
    int count = 0;
    for (j = 0; j < len; j++)
    {count=0;
        for (i = 0; i < n-1; i++)
        {
            if (arr[i][j] == arr[i + 1][j])
            {
                count++;
            }
        }
        if (count == n - 1)
            res++;
        else
        break;
    }
    for(i=0;i<res;i++)
    cout<<arr[0][i];
    return 0;
}