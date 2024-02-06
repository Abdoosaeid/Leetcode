
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (s[i] != ']') {
                // If the character is not ']', push it onto the stack as a string
                st.push(string(1, s[i]));
            } else {
                // If the character is ']', process the substring inside the brackets
                string sub = "";
                while (st.top() != "[") {
                    // Concatenate characters until '[' is encountered
                    sub = st.top() + sub;
                    st.pop();
                }
                st.pop();  // Pop '[' from the stack

                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    // Extract the number preceding '['
                    k = st.top() + k;
                    st.pop();
                }
                int n = stoi(k);  // Convert the extracted number to an integer

                string repeatedSub = "";
                while (n--) {
                    // Repeat the substring 'n' times
                    repeatedSub += sub;
                }

                st.push(repeatedSub);  // Push the repeated substring onto the stack
            }
        }

        string ans = "";
        while (!st.empty()) {
            // Concatenate all remaining elements on the stack
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
