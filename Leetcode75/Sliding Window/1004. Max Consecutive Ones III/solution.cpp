class Solution {
public:
    // Function to find the length of the longest subarray with at most k zeros
    int longestOnes(vector<int>& nums, int k) {
        int c = k, count = 0, sz = nums.size();
        int ans = 0;
        int l = 0, r = 0;

        // Sliding window approach
        while (l < sz && r < sz) {
            // If the current element is 1, move the right pointer and increase the count
            if (nums[r] == 1) {
                r++;
                count++;
            }
                // If the current element is 0 and there are remaining changes (k), move the right pointer, increase the count, and decrement the remaining changes
            else if (nums[r] == 0 && c > 0) {
                r++;
                count++;
                c--;
            }
                // If the current element is 0 and there are no remaining changes, move the left pointer, increment the remaining changes if the left element is 0, and decrement the count
            else {
                if (nums[l] == 0) {
                    c++;
                }
                l++;
                count--;
            }

            // Update the maximum length
            ans = max(ans, count);
        }

        // Return the maximum length
        return ans;
    }
};
