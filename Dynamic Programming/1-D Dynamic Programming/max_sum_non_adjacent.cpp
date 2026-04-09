// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Recursive function with memoization
//     int solve(vector<int>& arr, int i, vector<int>& dp) {
//         // If index is negative, no element to pick
//         if (i < 0) return 0;

//         // If at first element, return its value
//         if (i == 0) return arr[0];

//         // Return already computed value
//         if (dp[i] != -1) return dp[i];

//         // Include current and move 2 back
//         int pick = arr[i] + solve(arr, i - 2, dp);

//         // Exclude current and move 1 back
//         int notPick = solve(arr, i - 1, dp);

//         // Store and return max of both choices
//         return dp[i] = max(pick, notPick);
//     }

//     // Main function to be called externally
//     int maximumNonAdjacentSum(vector<int>& arr) {
//         int n = arr.size();

//         // DP array initialized with -1
//         vector<int> dp(n, -1);

//         // Start solving from last index
//         return solve(arr, n - 1, dp);
//     }
// };

// int main() {
//     vector<int> arr = {2, 1, 4, 9};
//     Solution obj;

//     // Output the result
//     cout << obj.maximumNonAdjacentSum(arr);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return maximum sum of non-adjacent elements
    int maxSum(vector<int>& nums) {
        // Handle edge case for empty input
        if (nums.empty()) return 0;

        // Initialize two tracking sums
        int prev2 = 0;
        int prev = nums[0];

        // Traverse through the array
        for (int i = 1; i < nums.size(); i++) {
            // Include current by adding it to two steps back
            int include = nums[i] + prev2;

            // Exclude current by taking previous best
            int exclude = prev;

            // Choose max of include and exclude
            int curr = max(include, exclude);

            // Update tracking variables
            prev2 = prev;
            prev = curr;
        }

        // Final result is stored in prev
        return prev;
    }
};

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    Solution obj;
    cout << obj.maxSum(arr) << endl;
    return 0;
}