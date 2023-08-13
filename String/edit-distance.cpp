#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
int edit(string s1, string s2, int a, int b)
{
    int dp[a + 1][b + 1];
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    return dp[a][b];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    cout << edit(s1, s2, n1, n2);
    return 0;
}