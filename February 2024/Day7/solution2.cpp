class Solution {
public:
    // Function to compare two characters based on their frequency
    static bool compare(pair<char, int> a, pair<char, int> b) {
        // Compare by frequency in descending order
        return a.second > b.second;
    }

    // Function to sort characters in the string based on their frequency
    string frequencySort(string s) {
        // Map to store character frequency
        unordered_map<char, int> mp;

        // Count the frequency of each character
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            mp[s[i]]++;
        }

        // Vector to store pairs of characters and their frequencies
        vector<pair<char, int>> charFrequency;

        // Copy data from the map to the vector
        for (auto m : mp) {
            charFrequency.push_back(m);
        }

        // Sort the vector based on character frequency
        sort(charFrequency.begin(), charFrequency.end(), compare);

        // Result string
        string ans = "";

        // Build the result string based on the sorted character frequencies
        for (auto m : charFrequency) {
            while (m.second-- > 0) {
                ans += m.first;
            }
        }

        return ans;
    }
};
