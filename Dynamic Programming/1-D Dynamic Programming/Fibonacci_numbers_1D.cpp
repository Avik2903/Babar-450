#include<bits/stdc++.h>
using namespace std;

/*int fibo(int n)
{
    vector<int> dp(n+1,-1);
    // if(n<=1) // O(N) and O(N)+O(N)
    //     return n;
    // if(dp[n]!=-1)
    //     return dp[n];
    // return dp[n]=fibo(n-1)+fibo(n-2);
    dp[0]=0;// O(N) and O(N)
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}*/

int main()
{
    int n=6;
    //cout<<fibo(n);
    int prev=1;
    int prev2=0;
    for(int i=2;i<=n;i++) /// O(N) and O(1)
    {
        int cur=prev+prev2;
        prev2=prev;
        prev=cur;
    }
    cout<<prev;
    return 0;
}