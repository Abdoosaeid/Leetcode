class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> st;
            for (int i = 0; i < traversal.size();) {
                int count = 0, num = 0;
                // Count the number of dashes (depth level)
                while (i < traversal.size() && traversal[i] == '-') {
                    count++;
                    i++;
                }
                // Get the node value
                while (i < traversal.size() && isdigit(traversal[i])) {
                    num = num * 10 + (traversal[i++] - '0');
                }
                TreeNode* node = new TreeNode(num);
    
                // Adjust stack to current depth
                while (st.size() > count) st.pop();
    
                // Attach the new node to the tree
                if (!st.empty()) {
                    if (!st.top()->left) {
                        st.top()->left = node;
                    } else {
                        st.top()->right = node;
                    }
                }
                
                // Push the current node onto the stack
                st.push(node);
            }
    
            // The root is at the bottom of the stack
            while (st.size() > 1) st.pop();
            return st.top();
        }
    };
    