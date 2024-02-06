class Solution {
public:
    // Function to group anagrams in a vector of strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store anagrams, where the key is the sorted string, and the value is a vector of anagrams
        map<string, vector<string>> mp;

        // Loop through each string in the input vector
        for (int i = 0, sz = strs.size(); i < sz; ++i) {
            // Create a copy of the current string
            string s = strs[i];

            // Sort the characters of the string to identify anagrams
            sort(s.begin(), s.end());

            // Add the original string to the corresponding group in the map
            mp[s].push_back(strs[i]);
        }

        // Vector to store the final result of grouped anagrams
        vector<vector<string>> ans;

        // Iterate through the map and add each group to the result vector
        for (auto& m : mp) {
            ans.push_back(m.second);
        }

        // Return the final vector of grouped anagrams
        return ans;
    }
};
