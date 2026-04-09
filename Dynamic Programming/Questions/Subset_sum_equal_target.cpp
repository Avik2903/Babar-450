// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Recursive helper function to check if a subset sum equals target
//     bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//         // Base case: target achieved
//         if (target == 0) return true;

//         // Base case: at the first index, check if it equals the target
//         if (ind == 0) return arr[0] == target;

//         // Check memoization table
//         if (dp[ind][target] != -1) return dp[ind][target];

//         // Choice 1: do not take the current element
//         bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

//         // Choice 2: take the current element if possible
//         bool taken = false;
//         if (arr[ind] <= target) {
//             taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
//         }

//         // Store result in DP table
//         return dp[ind][target] = notTaken || taken;
//     }

//     // Main function to check if subset with sum = k exists
//     bool subsetSumToK(int n, int k, vector<int>& arr) {
//         vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//         return subsetSumUtil(n - 1, k, arr, dp);
//     }
// };

// // Driver code
// int main() {
//     vector<int> arr = {1, 2, 3, 4};
//     int k = 4;
//     int n = arr.size();

//     Solution sol;
//     if (sol.subsetSumToK(n, k, arr))
//         cout << "Subset with the given target found";
//     else
//         cout << "Subset with the given target not found";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if there is a subset of 'arr' with sum equal to 'k' using space optimization
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Initialize a vector 'prev' to represent the previous row of the DP table
        vector<bool> prev(k + 1, false);

        // Base case: sum 0 can always be formed by empty subset
        prev[0] = true;

        // Base case: if first element <= k, mark true
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        // Iterate over all elements from second to last
        for (int ind = 1; ind < n; ind++) {
            vector<bool> cur(k + 1, false);
            cur[0] = true; // sum 0 is always possible

            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target]; // skip current element
                bool taken = false;

                if (arr[ind] <= target) {
                    taken = prev[target - arr[ind]]; // take current element
                }

                cur[target] = notTaken || taken; // store result for current target
            }

            prev = cur; // move to next iteration
        }

        // Final answer: can we form sum k using all elements?
        return prev[k];
    }
};

// Driver code
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
