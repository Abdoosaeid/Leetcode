class Solution {
public:
    // Function to find the single number that appears only once in the array
    int singleNumber(vector<int>& nums) {
        // Initialize the result variable to store the single number
        int result = 0;

        // Iterate through each element in the input vector
        for (int num : nums) {
            // XOR the current element with the result
            // This effectively cancels out duplicate numbers
            // and leaves the single number that appears only once
            result ^= num;
        }

        // Return the single number that appears only once
        return result;
    }
};
