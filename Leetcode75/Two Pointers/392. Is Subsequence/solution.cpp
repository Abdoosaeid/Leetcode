class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz_s = s.size();
        int sz_t = t.size();

        // If s is an empty string, it is always a subsequence of any string
        if (sz_s == 0) {
            return true;
        }

        // If the length of s is greater than the length of t, s cannot be a subsequence
        if (sz_s > sz_t) {
            return false;
        }

        // Initialize pointers for string traversal
        int l = 0; // Pointer for string s
        int r = 0; // Pointer for string t
        int count = 0; // Count of matching characters

        // Traverse both strings
        while (l < sz_s && r < sz_t) {
            if (s[l] == t[r]) {
                // If the characters match, move both pointers and increment the count
                l++;
                r++;
                count++;
            } else {
                // If the characters do not match, move the pointer in the larger string (t)
                r++;
            }

            // If the count becomes equal to the length of s, s is a subsequence
            if (count == sz_s) {
                return true;
            }
        }

        // If the loop completes and count is not equal to the length of s, s is not a subsequence
        return false;
    }
};
