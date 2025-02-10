// Solution 1 

class Solution {
public:
    string clearDigits(string s) {
        // Optimize input/output performance (not needed in this problem)
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

        stack<int> st;  // Stack to store non-digit characters
        string ans = ""; // Stores the final result

        // Iterate over each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {  // Check if the character is a digit (0-9)
                if (!st.empty()) {  // If the stack is not empty, remove the last stored character
                    st.pop();
                }
            } else {
                st.push(s[i]);  // If it's not a digit, push it onto the stack
            }
        }

        // Pop all characters from the stack and build the final string
        while (!st.empty()) {
            ans.push_back(st.top()); // Add the top character of the stack to the result string
            st.pop();  // Remove the top character from the stack
        }

        // Since stack stores characters in reverse order, we reverse the string to restore original order
        reverse(ans.begin(), ans.end());

        return ans;  // Return the final processed string
    }
};
/////////////////////////////////////////////////////////////////////////////////////////
//Solution 2 
class Solution {
public:
    string clearDigits(string s) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        
        string ans = "";  // Acts as a stack
        
        for (char c : s) {
            if (isdigit(c)) { 
                if (!ans.empty()) ans.pop_back(); // Remove last character
            } else {
                ans.push_back(c); // Append non-digit character
            }
        }
        
        return ans;
    }
};
