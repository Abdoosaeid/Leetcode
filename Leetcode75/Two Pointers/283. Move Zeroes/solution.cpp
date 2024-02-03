class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = -1;

        // Find the index of the first zero in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero is found, no need to proceed
        if (j == -1)
            return;

        // Move non-zero elements to the front, starting from the index of the first zero
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
