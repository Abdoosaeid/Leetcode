class Solution {
public:
    // Function to find the maximum number of vowels in a substring of length k
    int maxVowels(string s, int k) {
        int count = 0;

        // Calculate the number of vowels in the first k characters
        for (int i = 0; i < k; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        // Initialize the maximum count
        int ans = count;

        // Iterate through the string starting from index k
        for (int i = k, sz = s.size(); i < sz; ++i) {
            // Update the count when encountering a vowel at the current index
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }

            // Update the count when removing a vowel from the substring (sliding window)
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                count--;
            }

            // Update the maximum count
            ans = max(ans, count);
        }

        // Return the maximum count of vowels
        return ans;
    }
};
