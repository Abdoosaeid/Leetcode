class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if the concatenation of str1 and str2 is equal to the concatenation of str2 and str1
        if (str1 + str2 != str2 + str1) {
            // If not equal, there is no common prefix, so return an empty string
            return "";
        }

        // If the concatenations are equal, find the GCD of the lengths of str1 and str2
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
