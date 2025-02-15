class Solution {
    public:
        // Function to check if a number 'num' can be partitioned such that its sum equals 'target'
        bool Partition(int num, int target) {
            // If the target becomes negative or num is smaller than target, return false
            if (target < 0 || num < target) {
                return false;
            }
    
            // If num is exactly equal to target, return true (successful partition)
            if (num == target) {
                return true;
            }
    
            // Try different ways of partitioning the number:
            // 1. Remove the last digit and check if the remaining number satisfies the condition.
            // 2. Remove the last two digits and check.
            // 3. Remove the last three digits and check.
            return Partition(num / 10, target - num % 10) || 
                   Partition(num / 100, target - num % 100) || 
                   Partition(num / 1000, target - num % 1000);
        }
    
        // Function to calculate the "punishment number" up to 'n'
        int punishmentNumber(int n) {
            int punishmentNum = 0; // Variable to store the sum of valid squares
    
            // Iterate over numbers from 1 to n
            for (int i = 1; i <= n; i++) {
                int square = i * i; // Compute the square of the current number
    
                // Check if the square can be partitioned to sum up to 'i'
                if (Partition(square, i)) {
                    punishmentNum += square; // If true, add the square to the result
                }
            }
    
            return punishmentNum; // Return the total punishment number
        }
    };
    