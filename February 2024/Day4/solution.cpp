class Solution {
public:
    // Function to find the minimum window substring
    string minWindow(string s, string t) {
        // Special cases
        if (s == t) {
            return s; // If both strings are equal, return the entire string
        }
        if (t.size() > s.size() || s.empty() || t.empty()) {
            return ""; // If t is longer than s, or if either string is empty, return an empty string
        }

        // Map to store the count of characters in string t
        unordered_map<char, int> m;
        for (auto x : t) m[x]++; // Count occurrences of characters in t

        int low = 0; // Start of the window
        int counter = 0; // Counter to track matching characters
        int min_length = INT_MAX; // Minimum length of the window
        int start = 0; // Start index of the minimum window substring

        // Iterate through the string s
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] > 0) {
                counter++; // Increment counter for matching character
            }
            m[s[i]]--; // Decrement count for the character in the map

            // Check if all characters in t are matched
            if (counter == t.size()) {
                // Shrink the window by moving the low pointer
                while (low < i && m[s[low]] < 0) {
                    m[s[low++]]++; // Increment count for the character in the map
                }

                // Update minimum window length and start index
                if (min_length > i - low + 1) {
                    min_length = i - low + 1;
                    start = low;
                }
            }
        }

        // Check if a valid window was found
        return min_length == INT_MAX ? "" : s.substr(start, min_length);
    }
};
