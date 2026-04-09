// #include<bits/stdc++.h>
// using namespace std;

// int solve(int ind,int tar,vector<int>& nums, vector<vector<int>>& dp)
// {
//     if(tar==0)  return 1;
//     if(ind==0)  return (nums[0]==tar ? 1 : 0);
//     if(dp[ind][tar]!=-1)    return dp[ind][tar];

//     int notpick=solve(ind-1,tar,nums,dp);
//     int pick=0;
//     if(nums[ind]<=tar)
//         pick=solve(ind-1,tar-nums[ind],nums,dp);
//     return dp[ind][tar]=pick+notpick;
// }

// int countsub(vector<int>& nums,int tar)
// {
//     int n=nums.size();
//     vector<vector<int>> dp(n,vector<int>(tar+1,-1));
//     return solve(n-1,tar,nums,dp);
// }

// int main()
// {
//     vector<int> nums = {1, 2, 2, 3};
//     int target = 3;
//     cout<<countsub(nums,target);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Counts the number of subsets of an array that sum to a target value K.
     * 
     * This function uses dynamic programming to find all possible subsets whose elements
     * add up to exactly K. It employs a tabulation approach where for each element,
     * it tracks how many ways we can achieve each possible sum.
     * 
     * @param arr Reference to a vector of integers representing the input array
     * @param K The target sum we want to find subsets for
     * 
     * @return The number of subsets that have a sum equal to K
     * 
     * @details
     * Algorithm:
     * - Uses a 1D DP array where dp[t] represents the count of subsets with sum t
     * - Base case: dp[0] = 1 (empty set has sum 0)
     * - For each element, creates a temporary DP array considering:
     *   - "Not taking" the current element: inherits counts from previous state
     *   - "Taking" the current element: adds counts from (t - arr[i]) if valid
     * - Time Complexity: O(n * K) where n is the size of array
     * - Space Complexity: O(K) for the DP array
     * 
     * @example
     * If arr = [1, 2, 3] and K = 3:
     * Subsets: {3}, {1, 2}
     * Returns: 2
     */
    int countSubsets(vector<int>& arr, int K) {
        // Create a dp array of size K+1 initialized to 0
        vector<int> dp(K + 1, 0);

        // Base case: One subset (empty set) makes sum 0
        dp[0] = 1;

        // If first element <= K, mark it as a subset
        if (arr[0] <= K) dp[arr[0]] += 1;

        // Loop through elements starting from index 1
        for (int i = 1; i < arr.size(); i++) {
            // Create a temporary dp array for current element
            vector<int> curr(K + 1, 0);

            // Empty set always makes sum 0
            curr[0] = 1;

            // Iterate over all possible targets
            for (int t = 0; t <= K; t++) {
                // Exclude current element
                int notTake = dp[t];

                // Include current element if possible
                int take = 0;
                if (arr[i] <= t) {
                    take = dp[t - arr[i]];
                }

                // Total ways = include + exclude
                curr[t] = take + notTake;
            }

            // Update dp for next iteration
            dp = curr;
        }

        // Return answer for sum K
        return dp[K];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int K = 4;
    cout << sol.countSubsets(arr, K) << endl; 
    return 0;
}
