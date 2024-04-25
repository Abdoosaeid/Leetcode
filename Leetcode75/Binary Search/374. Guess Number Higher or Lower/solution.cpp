class Solution {
public:
    // Function to guess the number
    int guessNumber(int n) {
        long long l = 1, r = n; // Initialize the search range
        long long x = n; // Initialize the result to n

        // Binary search loop
        while (l <= r) {
            unsigned long long mid = (l + r) / 2; // Calculate the middle value

            // Guess the number and check the result
            if (guess(mid) == 0) { // If the guess is correct
                x = mid; // Update the result
                break; // Exit the loop
            } else if (guess(mid) == -1) { // If the guess is higher than the picked number
                r = mid - 1; // Adjust the upper bound of the search range
            } else { // If the guess is lower than the picked number
                l = mid + 1; // Adjust the lower bound of the search range
            }
        }

        return x; // Return the result
    }
};
