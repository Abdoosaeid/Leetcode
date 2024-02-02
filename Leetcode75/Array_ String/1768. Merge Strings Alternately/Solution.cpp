class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString = ""; // Initialize the result string
        int i = 0; // Initialize a counter

        // Continue merging until the end of either word1 or word2
        while (i < word1.length() || i < word2.length()) {
            // If there are characters remaining in word1, append the i-th character
            if (i < word1.size()) {
                mergedString.push_back(word1[i]);
            }

            // If there are characters remaining in word2, append the i-th character
            if (i < word2.size()) {
                mergedString.push_back(word2[i]);
            }

            i++; // Move to the next character
        }

        return mergedString; // Return the merged string
    }
};
