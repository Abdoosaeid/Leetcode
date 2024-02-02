class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a;  // Vector to store the result
        int zeros = count(nums.begin(), nums.end(), 0);  // Count the number of zeros in the array

        // Case 1: No Zero in the Array
        if (!zeros) {
            long long ans = 1;  // Initialize a variable to store the product of all elements

            // Calculate the product of all elements in the array
            for (int i = 0, sz = nums.size(); i < sz; ++i) {
                ans *= nums[i];
            }

            // Calculate the result by dividing the total product by the element at each index
            for (int i = 0, sz = nums.size(); i < sz; ++i) {
                a.push_back(ans / nums[i]);
            }
        }
            // Case 2: One Zero in the Array
        else if (zeros == 1) {
            long long ans = 1;  // Initialize a variable to store the product of non-zero elements

            // Calculate the product of non-zero elements in the array
            for (int i = 0, sz = nums.size(); i < sz; ++i) {
                if (nums[i] == 0) {
                    continue;
                }
                ans *= nums[i];
            }

            // Calculate the result:
            // - If the current element is zero, the result is the product of all non-zero elements.
            // - Otherwise, the result is zero.
            for (int i = 0, sz = nums.size(); i < sz; ++i) {
                if (nums[i] == 0) {
                    a.push_back(ans);
                    continue;
                }
                a.push_back(0);
            }
        }
            // Case 3: More than One Zero in the Array
        else {
            // In this case, the result for each index is zero.
            for (int i = 0, sz = nums.size(); i < sz; ++i) {
                a.push_back(0);
            }
        }

        return a;  // Return the result vector
    }
};
