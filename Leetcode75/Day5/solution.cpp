class Solution {
public:
    // Function to find the index of the first non-repeating character in the string
    int firstUniqChar(string s) {
        // Map to store the frequency of each character
        map<char, int> mp;

        // Loop through the string to calculate the frequency of each character
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            mp[s[i]]++;
        }

        // Loop through the string again to find the first non-repeating character
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            // If the frequency of the current character is 1, it is the first non-repeating character
            if (mp[s[i]] == 1) {
                return i;
            }
        }

        // If no non-repeating character is found, return -1
        return -1;
    }
};
