class Solution {
    public:
        // Variable to store the length of binary strings
        int n;
        // Unordered set to store the input binary strings for fast lookup
        unordered_set<string> st;
    
        // Recursive function to generate a binary string not in the set
        string generate(string s) {
            // Base case: If the length of the current string is equal to n
            if(s.size() == n) {
                // Check if the generated string is not in the set
                if(st.find(s) == st.end()) {
                    // If it's not in the set, return this as the required unique string
                    return s;
                }
                // If it's in the set, return an empty string
                return "";
            }
    
            // Try to generate the string by adding '0' to the current string
            string add_zero = generate(s + "0");
            // If the result is a non-empty string, return it
            if(add_zero.size() > 0) {
                return add_zero;
            }
    
            // Otherwise, try to generate the string by adding '1'
            return generate(s + "1");
        }
    
        // Main function to find a binary string different from all in nums
        string findDifferentBinaryString(vector<string>& nums) {
            // Set the length of binary strings (since all are of the same length)
            n = nums.size();
            
            // Insert all the binary strings from nums into the set for fast lookup
            for(string s : nums) {
                st.insert(s);
            }
    
            // Start generating the string from an empty string
            return generate("");
        }
    };
    