class Solution {
    public:
        string getHappyString(int n, int k) {
            stack<string> st;  // Stack to store strings while generating happy strings
            int index = 0;     // Counter to track the k-th happy string
            st.push("");       // Start with an empty string
    
            // Perform DFS using a stack
            while (!st.empty()) {
                string cur = st.top();  // Get the top element
                st.pop();               // Remove it from the stack
    
                // If the current string has reached the desired length n
                if (cur.size() == n) {
                    index++; // Increment the index (we've found a new happy string)
    
                    // If this is the k-th happy string, return it
                    if (index == k) {
                        return cur;
                    }
                    continue; // Move to the next possible string
                }
    
                // Generate possible next characters ('a', 'b', 'c')
                for (char c = 'c'; c >= 'a'; c--) { // Reverse order to maintain lexicographical order
                    // Ensure no two consecutive characters are the same
                    if (!cur.empty() && cur.back() == c) {
                        continue;
                    }
                    st.push(cur + c); // Add the new string to the stack
                }
            }
    
            // If the k-th happy string does not exist, return an empty string
            return "";
        }
    };
    