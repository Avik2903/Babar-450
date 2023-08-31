#include <bits/stdc++.h>
using namespace std;
#define max 5
void getallpath(int arr[max][max], int n, int row, int col, vector<string> &ans, string cur)
{
    if (row >= n or col >= n or row < 0 or col < 0 or arr[row][col] == 0)
        return;

    if (row == n - 1 and col == n - 1)
    {
        ans.push_back(cur);
        return;
    }
    arr[row][col] = 0;

    getallpath(arr, n, row - 1, col, ans, cur + "U");
    getallpath(arr, n, row, col + 1, ans, cur + "R");
    getallpath(arr, n, row, col - 1, ans, cur + "L");
    getallpath(arr, n, row + 1, col, ans, cur + "D");

    arr[row][col] = 1;

    return;
}
vector<string> findPath(int arr[max][max], int n)
{
    vector<string> ans;
    getallpath(arr, n, 0, 0, ans, "");
    return ans;
}
int main()
{
    int arr[max][max];
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            cin>>arr[i][j];
        }
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<string> ans = findPath(arr, n);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}