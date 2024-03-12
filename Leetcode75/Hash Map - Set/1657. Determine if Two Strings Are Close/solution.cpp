class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Initialize vectors and maps to store character frequencies
        vector<int> v1, v2;  // Vectors to store frequencies of characters
        map<char, int> mp1, mp2;  // Maps to count occurrences of characters

        // Check if the lengths of word1 and word2 are equal
        if (word1.size() != word2.size()) {
            return false;  // If not, they can't be close strings
        }

        // Convert word1 and word2 into sets to check for the same set of characters
        unordered_set<char> set3(word1.begin(), word1.end());
        unordered_set<char> set4(word2.begin(), word2.end());

        // If the sets are not equal, the strings can't be close strings
        if (set3 != set4) {
            return false;
        }

        // Iterate through each character in word1 and word2 to count occurrences
        for (int i = 0; i < word1.size(); ++i) {
            mp1[word1[i]]++;  // Increment the count of the character in word1
            mp2[word2[i]]++;  // Increment the count of the character in word2
        }

        // Populate vectors v1 and v2 with the frequencies from maps mp1 and mp2
        for (auto &i : mp1) {
            v1.push_back(i.second);  // Push the freque
