#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& arr,int n,vector<int>& dp) // memorisation
{
    if(n==0 && n==1)    return arr[n];
    if(n<0) return 0;
    if(dp[n]!=-1)   return dp[n];
    int step1= f(arr,n-1,dp);
    int step2=f(arr,n-2,dp);
    //dp[n]=arr[n]+min(f(arr,n-1,dp),f(arr,n-2,dp));
    return dp[n]=arr[n]+min(step1,step2);;
}
int mincost(vector<int>& arr,int n) 
{
    vector<int> dp(n,-1);
    return min(f(arr,n-1,dp),f(arr,n-2,dp));
}

int minCostClimbingStairs(vector<int>& cost,int n) { // tabulation
	int first = cost[0];
	int second = cost[1];
	if (n<=2) return min(first, second);
	for (int i=2; i<n; i++) {
		int curr = cost[i] + min(first, second);
		first = second;
		second = curr;
	}
	return min(first, second);
    }


int main()
{
    vector<int> arr = {10,15,20};
    int n=arr.size();
    cout<<mincost(arr,n)<<endl<< minCostClimbingStairs(arr,n);
    return 0;
}