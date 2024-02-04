class Solution {
public:
    // Function to find the length of the longest subarray with at most one zero
    int longestSubarray(std::vector<int>& nums) {
        int count = 0, c = 0, ans = 0;
        int l = 0, r = 0;
        int sz = nums.size();

        // Skip leading zeros
        while (r < sz && nums[r] == 0) {
            r++, l++;
        }

        // If all elements are zeros, the length is 0
        if (r == sz) {
            return 0;
        }

        // Count the number of ones in the array
        int ones = std::count(nums.begin(), nums.end(), 1);

        // If all elements are ones, return the size of the array minus one
        if (ones == sz) {
            return sz - 1;
        }

        // Sliding window approach
        while (r < sz && l < sz) {
            // If the current element is 1 and there is at least one change available, move the right pointer and increase the count
            if (nums[r] && c >= 0) {
                r++;
                count++;
            }
                // If the current element is 0 and no change is available, move the right pointer and set the change count to 1
            else if (nums[r] == 0 && c == 0) {
                r++;
                c = 1;
            }
                // If the current element is 0 and a change is available, handle cases where consecutive zeros are encountered
            else {
                // If left and right pointers are at the same position, reset the count and skip consecutive zeros
                if (l == r) {
                    count = 0;
                    while (nums[r] == 0) {
                        l++;
                        r++;
                        c = 0;
                    }
                }
                // If the left element is 1, move the left pointer and decrease the count
                if (nums[l]) {
                    l++;
                    count--;
                }
                    // If the left element is 0, move the left pointer and reset the change count
                else {
                    l++;
                    c = 0;
                }
            }
            // Update the maximum length
            ans = std::max(ans, count);
        }

        // Return the maximum length
        return ans;
    }
};
