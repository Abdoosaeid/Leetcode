class Solution {
public:
    vector<int> countBits(int n) {
        // Create a vector to store the count of set bits for each integer from 0 to n
        vector<int> ans;

        // Iterate through each integer from 0 to n
        for(int i = 0; i <= n; i++) {
            int sum = 0; // Initialize a variable to store the count of set bits for the current integer

            // Count the set bits in the binary representation of the current integer
            int num = i; // Initialize a variable to hold the current integer
            while(num) {
                sum += (num & 1); // Check if the least significant bit is set (bitwise AND with 1)
                num /= 2; // Shift the bits to the right by one position (equivalent to dividing by 2)
            }

            // Push the count of set bits for the current integer into the vector
            ans.push_back(sum);
        }

        // Return the vector containing the counts of set bits for integers from 0 to n
        return ans;
    }
};
