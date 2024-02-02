class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Get the size of the candies vector
        int sz = candies.size();

        // Initialize a vector of flags to store whether each child can have the greatest candies
        vector<bool> flag(sz);

        // Find the maximum number of candies among all children
        int mx = *max_element(candies.begin(), candies.end());

        // Iterate through each child's candies
        for (int i = 0; i < sz; ++i) {
            // Check if the current child, with extra candies, can have the greatest number of candies
            if (candies[i] + extraCandies >= mx) {
                flag[i] = true; // Set the flag to true if the condition is met
            } else {
                flag[i] = false; // Set the flag to false otherwise
            }
        }

        // Return the vector of flags indicating whether each child can have the greatest candies
        return flag;
    }
};
