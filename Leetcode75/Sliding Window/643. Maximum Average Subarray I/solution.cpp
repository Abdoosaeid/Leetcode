class Solution {
public:
    // Function to find the maximum average of a subarray of length k
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; ++i) {
            ans += static_cast<double>(nums[i]);
        }

        // If k is equal to the size of nums, return the average of the entire array
        if (k == nums.size()) {
            return ans / k;
        }

        double count = ans;

        // Iterate through the array starting from index k
        for (int i = k, sz = nums.size(); i < sz; ++i) {
            // Update the running sum by adding the current element and subtracting the element at i-k
            count += nums[i];
            count -= nums[i - k];

            // Update the maximum average
            ans = max(ans, count);
        }

        // Return the maximum average
        return ans / k;
    }
};
