class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Initialize two maps to store element frequencies
        map<int, int> mp1, mp2;

        // Count the occurrences of each element in the array
        for (int i = 0; i < arr.size(); ++i) {
            mp1[arr[i]]++;
        }

        // Check if the frequencies of occurrences are unique
        for(auto &i : mp1) {
            if (mp2[i.second] > 0) {
                // If frequency is not unique, return false
                return false;
            }
            // Store the frequency in the second map
            mp2[i.second]++;
        }

        // If all frequencies are unique, return true
        return true;
    }
};
