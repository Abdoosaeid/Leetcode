class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; // Pointer to the leftmost element of the container
        int r = height.size() - 1; // Pointer to the rightmost element of the container
        int ans = 0; // Variable to store the maximum area

        // Continue the loop as long as the left pointer is less than the right pointer
        while (l < r) {
            // Calculate the area between the current pair of vertical lines
            int currentArea = min(height[l], height[r]) * (r - l);

            // Update the maximum area if the current area is greater
            ans = max(currentArea, ans);

            // Move the pointers based on the height of the vertical lines
            if (height[l] > height[r]) {
                r--; // Move the right pointer towards the center
            } else {
                l++; // Move the left pointer towards the center
            }
        }

        // Return the maximum area found
        return ans;
    }
};
