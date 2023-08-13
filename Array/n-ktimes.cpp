#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = n / k;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (auto i : freq)
    {
        if (i.second > x)
        {
            cout << i.first << endl;
        }
    }
return 0;
}
