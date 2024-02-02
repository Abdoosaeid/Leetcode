class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Check if there are no flowers to be placed
        if (!n) {
            return true;
        }

        // Add dummy elements (0s) at the beginning and end of the flowerbed to simplify boundary checks
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);

        // Iterate through the flowerbed
        for (int i = 1, sz = flowerbed.size(); i < sz - 1; ++i) {
            // Check if the current position is empty and the adjacent positions are also empty
            if (flowerbed[i] == 0 && flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
                n--; // Decrease the number of flowers to be placed
                flowerbed[i] = 1; // Place a flower at the current position
            }
        }

        // Return whether all flowers have been placed
        return n <= 0;
    }
};
