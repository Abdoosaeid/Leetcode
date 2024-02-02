class Solution {
public:
    string reverseWords(string s) {
        vector<string> x;  // Vector to store individual words
        string s1 = "";    // Temporary string to build each word

        // Iterate through the characters in the input string
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (s[i] == ' ') {
                // If a space is encountered, push the current word to the vector and reset s1
                x.push_back(s1);
                s1 = "";
            } else {
                // If a non-space character is encountered, append it to the current word
                s1 += s[i];
            }
        }

        // Push the last word (or the only word if no space is present) to the vector
        x.push_back(s1);

        string ans = "";

        // Build the reversed string by appending words from the vector in reverse order
        while (x.size()) {
            ans += x.back();

            // Append a space if the current word is not empty
            if (x.back() != "") {
                ans += ' ';
            }

            x.pop_back();  // Remove the last word from the vector
        }

        ans.pop_back();  // Remove the trailing space
        return ans;
    }
};
