class Solution {
public:
    // Helper function to recursively solve the problem and memoize results
    int solve(vector<int>& arr, int x, int k, int n, vector<int>& dp) {
        // Base case: if x exceeds the array size, return 0
        if (x >= n) {
            return 0;
        }

        // If the result for the current index x is already calculated, return it
        if (dp[x] != -1) {
            return dp[x];
        }

        int mx = INT_MIN;  // Variable to store the maximum element in the current subarray
        int sum = 0;       // Variable to store the maximum sum for the current subarray

        // Iterate through the subarray from index x to min(x+k, n)
        for (int i = x; i < min(x + k, n); i++) {
            mx = max(mx, arr[i]);  // Update the maximum element in the subarray
            // Recursively calculate the sum for the next subarray and update the maximum sum
            sum = max(sum, solve(arr, i + 1, k, n, dp) + (i - x + 1) * mx);
        }

        // Memoize the result for the current index x and return the maximum sum
        return dp[x] = sum;
    }

    // Main function to find the maximum sum after partitioning the array
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);  // Memoization array to store calculated results
        return solve(arr, 0, k, n, dp);  // Call the helper function with initial parameters
    }
};
