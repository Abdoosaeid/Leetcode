class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the minimum number of perfect squares required for each number up to n
        vector<int> dp(n + 1, INT_MAX);

        // Base case: zero perfect squares are needed to represent 0
        dp[0] = 0;

        // Iterate through numbers from 1 to n
        for(int i = 1; i <= n; ++i) {
            // Initialize a variable to store the minimum number of squares for the current number i
            int mn = INT_MAX;

            // Check for each perfect square less than or equal to i
            for(int j = 1; j * j <= i; ++j) {
                // Update the minimum number of squares for the current number i
                mn = min(mn, dp[i - j * j] + 1);
            }

            // Update the dp array with the minimum number of squares for the current number i
            dp[i] = mn;
        }

        // Return the minimum number of squares required to represent the number n
        return dp[n];
    }
};
