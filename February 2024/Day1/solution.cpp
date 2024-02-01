class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Initialize a vector to store the divided arrays
        vector<vector<int>> v;

        // Sort the input array in ascending order
        sort(nums.begin(), nums.end());

        // Iterate through the array to find triplets
        for (int i = 0; i + 2 < nums.size(); ++i) {
            // Check if the current index is a multiple of 3
            if (i % 3 == 0) {
                // Check if the difference between the third and first element in the triplet is less than or equal to k
                if (nums[i + 2] - nums[i] <= k) {
                    // If the condition is met, add the triplet to the result vector
                    v.push_back({nums[i], nums[i + 1], nums[i + 2]});
                } else {
                    // If the condition is not met, return an empty vector
                    return {};
                }
            }
        }

        // Return the vector containing the divided arrays
        return v;
    }
};
