class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int l = INT_MAX, r = INT_MAX, mid = INT_MAX;  // Initialize three variables for the triplet subsequence

        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // Check if the current element is greater than the mid element
            if (nums[i] > mid) {
                return true;  // If yes, an increasing triplet subsequence is found
            }

            // Update the left, mid, and right elements based on the current element
            if (nums[i] < l) {
                l = nums[i];
            } else if (nums[i] > l && nums[i] < mid) {
                mid = nums[i];
            }
        }

        return false;  // No increasing triplet subsequence found
    }
};
