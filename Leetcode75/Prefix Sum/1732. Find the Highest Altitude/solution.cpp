class Solution {
public:
    // Function to find the largest altitude
    int largestAltitude(vector<int>& gain) {
        int ans = 0; // Variable to store the largest altitude
        int count = 0; // Variable to keep track of the current altitude

        // Loop through the elements in the 'gain' vector
        for (int i = 0, sz = gain.size(); i < sz; ++i) {
            // Update the current altitude by adding the gain at the current position
            count += gain[i];

            // Update the largest altitude if the current altitude is greater
            ans = max(ans, count);
        }

        // Return the largest altitude
        return ans;
    }
};
