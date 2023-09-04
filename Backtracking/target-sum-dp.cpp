#include <bits/stdc++.h>
using namespace std;
bool issum(int arr[], int n, int sum)
{
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
            {
                subset[i][j] = true;
            }
            else if (i == 0)
            {
                subset[i][j] = false;
            }
            else if (j == 0)
            {
                subset[i][j] = true;
            }
            else
            {
                if (j < arr[i - 1])
                    subset[i][j] = subset[i - 1][j];
                if (j >= arr[i - 1])
                    subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
            }
        }
    }
}
int main()
{
    int arr[] = {2, 8, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 12;
    if (issum(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}