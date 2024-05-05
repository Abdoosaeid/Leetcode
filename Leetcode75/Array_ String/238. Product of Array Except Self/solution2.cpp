class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Disable synchronization with C standard streams for faster I/O
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int sz = nums.size(); // Size of the input array
        vector<int> prefix(sz, 1), suffix(sz, 1), ans(sz); // Initialize vectors for prefix, suffix, and result

        // Populate the prefix product vector
        prefix[0] = nums[0]; // Set the first element of prefix to the first element of nums
        for (int i = 1; i < sz; ++i) {
            prefix[i] = prefix[i - 1] * nums[i]; // Calculate the prefix product
        }

        // Populate the suffix product vector
        suffix[sz - 1] = nums[sz - 1]; // Set the last element of suffix to the last element of nums
        for (int i = sz - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i]; // Calculate the suffix product
        }

        // Calculate the result
        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                ans[i] = suffix[i + 1]; // If i is the first index, set ans[i] to the product of all elements after nums[i]
            } else if (i == sz - 1) {
                ans[i] = prefix[i - 1]; // If i is the last index, set ans[i] to the product of all elements before nums[i]
            } else {
                ans[i] = prefix[i - 1] * suffix[i + 1]; // Otherwise, set ans[i] to the product of elements before and after nums[i]
            }
        }

        return ans; // Return the result vector
    }
};
