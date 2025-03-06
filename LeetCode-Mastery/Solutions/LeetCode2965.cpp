class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size(); // Get the size of the grid (n x n)
            int missing = -1, repeat = -1; // Variables to store the missing and repeated values
    
            unordered_map<int, int> freq; // Hash map to store the frequency of each number
    
            // Step 1: Count the occurrences of each number in the grid
            for (auto &r : grid) { // Loop through each row in the grid
                for (int num : r) { // Loop through each number in the row
                    freq[num]++; // Increment the frequency count for the number
                }
            }
    
            // Step 2: Identify the missing and repeated numbers
            for (int num = 1; num <= n * n; num++) { // Iterate through numbers from 1 to n^2
                if (!freq.count(num)) { // If the number is not found in the frequency map
                    missing = num;  // It is the missing number
                } 
                else if (freq[num] == 2) { // If a number appears twice
                    repeat = num; // It is the repeated number
                }
            }
    
            // Step 3: Return the result as a vector {repeated number, missing number}
            return {repeat, missing};
        }
    };
    