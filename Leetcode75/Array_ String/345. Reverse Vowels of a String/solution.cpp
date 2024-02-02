class Solution {
public:
    string reverseVowels(string s) {
        // Initialize pointers for the left and right ends of the string
        int l = 0;
        int r = s.size() - 1;

        // Continue swapping vowels from the left and right ends until the pointers meet
        while (l < r) {
            // Skip non-vowels from the left
            if (tolower(s[l]) != 'a' && tolower(s[l]) != 'e' && tolower(s[l]) != 'o' && tolower(s[l]) != 'u' && tolower(s[l]) != 'i') {
                l++;
                continue;
            }

            // Skip non-vowels from the right
            if (tolower(s[r]) != 'a' && tolower(s[r]) != 'e' && tolower(s[r]) != 'o' && tolower(s[r]) != 'u' && tolower(s[r]) != 'i') {
                r--;
                continue;
            }

            // Swap vowels
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;

            // Move pointers inward
            l++;
            r--;
        }

        // Return the string with reversed vowels
        return s;
    }
};
