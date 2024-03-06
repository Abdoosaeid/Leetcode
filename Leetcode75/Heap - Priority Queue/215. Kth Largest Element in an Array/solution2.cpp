class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());

        // Return the kth largest element from the end of the sorted vector
        return nums[nums.size() - k];
    }
};
