class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // Create a map to store the frequencies of rows in the grid
        map<vector<int>, int> mp;

        // Initialize a counter to store the count of equal pairs
        int count = 0;

        // Iterate over each row in the grid
        for (int i = 0; i < grid.size(); ++i) {
            // Increment the count of the current row in the map
            mp[grid[i]]++;
        }

        // Iterate over each column in the grid
        for (int i = 0; i < grid[0].size(); ++i) {
            // Create a vector to store the elements of the current column
            vector<int> v;

            // Extract the elements of the current column and store them in the vector
            for (int j = 0; j < grid.size(); ++j) {
                v.push_back(grid[j][i]);
            }

            // Check if the vector representing the current column exists in the map
            // If it does, add the frequency count of that vector to the total count
            if (mp[v] > 0) {
                count += mp[v];
            }
        }

        // Return the total count of equal pairs
        return count;
    }
};
