// solution 1 
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
            stack<char> st;
            int partSize = part.size();
            
            for (char ch : s) {
                st.push(ch);  // Push current character
                
                // Check if the top of the stack contains 'part'
                if (st.size() >= partSize) {
                    string temp = "";
                    // Extract last 'partSize' characters from stack
                    for (int i = 0; i < partSize; i++) {
                        temp = st.top() + temp;
                        st.pop();
                    }
                    // If it doesn't match 'part', push back characters
                    if (temp != part) {
                        for (char c : temp) {
                            st.push(c);
                        }
                    }
                }
            }
            
            // Construct final string from stack
            string result = "";
            while (!st.empty()) {
                result = st.top() + result;
                st.pop();
            }
            
            return result;
        }
    };

