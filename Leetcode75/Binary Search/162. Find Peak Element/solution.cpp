class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Get the size of the array - 1 (index of last element)
        int sz = nums.size() - 1;
        // Initialize left and right pointers for binary search
        int l = 0, r = sz;
        // Binary search loop
        while (l <= r) {
            // Calculate the middle index
            int mid = l + (r - l) / 2;

            // If the middle element is less than its left neighbor,
            // move the right pointer to mid - 1
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                r = mid - 1;
            }
                // If the middle element is less than its right neighbor,
                // move the left pointer to mid + 1
            else if (mid < sz && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
                // If the above conditions are not met, it means we've found a peak
                // Return the index of the peak element
            else {
                return mid;
            }
        }
        // Return 0 if no peak is found (should not happen for valid inputs)
        return 0;
    }
};
