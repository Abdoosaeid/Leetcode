class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0; // Initialize the answer variable to count the number of flips
        while (a || b || c) { // Continue the loop until all bits of a, b, and c are processed
            if (c & 1) { // If the rightmost bit of c is 1
                if (!(a & 1) && !(b & 1)) { // If both the rightmost bits of a and b are 0
                    ans++; // Increment the answer since a bit flip is required to set the corresponding bit of c
                }
            } else { // If the rightmost bit of c is 0
                if (a & 1) { // If the rightmost bit of a is 1
                    ans++; // Increment the answer since a bit flip is required to clear the corresponding bit of c
                }
                if (b & 1) { // If the rightmost bit of b is 1
                    ans++; // Increment the answer since a bit flip is required to clear the corresponding bit of c
                }
            }
            // Right shift a, b, and c to process the next bits
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans; // Return the minimum number of flips
    }
};
