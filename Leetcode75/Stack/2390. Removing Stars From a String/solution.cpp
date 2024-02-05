class Solution {
public:
    // Function to remove '*' characters from the string
    string removeStars(string s) {
        // Stack to store characters while processing the string
        stack<char> st;

        // Loop through the string
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            // If the current character is not '*', push it onto the stack
            if (s[i] != '*') {
                st.push(s[i]);
            } else {
                // If the current character is '*', pop the top element from the stack (if the stack is not empty)
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        // String to store the result
        string ans = "";

        // Reconstruct the string by popping elements from the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse the string to get the correct order
        reverse(ans.begin(), ans.end());

        // Return the final result
        return ans;
    }
};
