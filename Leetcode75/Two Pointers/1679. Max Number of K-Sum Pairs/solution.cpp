// The following line is a C++ lambda expression that speeds up input/output operations
// by turning off synchronization with the C standard input/output streams.
int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;} ();

class Solution {
public:
    // Function to find the maximum number of operations to make pairs with a sum equal to k
    int maxOperations(vector<int>& nums, int k) {
        int l = 0; // Pointer to the leftmost element of the sorted array
        int r = nums.size() - 1; // Pointer to the rightmost element of the sorted array
        sort(nums.begin(), nums.end()); // Sorting the input array in ascending order
        int count = 0; // Variable to store the count of pairs with sum equal to k

        // Continue the loop as long as the left pointer is less than the right pointer
        while (l < r) {
            // If the sum of the elements at pointers l and r is equal to k
            if (nums[l] + nums[r] == k) {
                l++; // Move the left pointer towards the center
                r--; // Move the right pointer towards the center
                count++; // Increment the count of pairs
            }
                // If the sum is less than k, move the left pointer to the right
            else if (nums[l] + nums[r] < k) {
                l++;
            }
                // If the sum is greater than k, move the right pointer to the left
            else if (nums[l] + nums[r] > k) {
                r--;
            }
        }

        // Return the count of pairs with sum equal to k
        return count;
    }
};
