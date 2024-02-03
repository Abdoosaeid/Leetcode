class Solution {
public:
    // Function to find the pivot index
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size(); // Get the size of the input vector

        // Calculate the cumulative sum of elements in the vector
        for (int i = 1; i < sz; ++i) {
            nums[i] += nums[i - 1];
        }

        // Check if the last element is equal to the first element
        if (nums[sz - 1] == nums[0]) {
            return 0; // If true, the pivot index is 0
        }

        // Iterate through the vector to find the pivot index
        for (int i = 1; i < sz; ++i) {
            // If the sum of elements after the current index is equal to the sum before the current index
            if (nums[sz - 1] - nums[i] == nums[i - 1]) {
                return i; // Return the current index as the pivot index
            }
        }

        return -1; // If no pivot index is found, return -1
    }
};
