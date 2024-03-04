class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Step 1: Initialize a queue for level-order traversal
        queue<TreeNode*> Nodes_queue;
        if (!root) {
            return {}; // Return an empty vector if the tree is empty
        }
        Nodes_queue.push(root);

        // Step 2: Initialize the result vector
        vector<int> ans;

        // Step 3: Perform level-order traversal
        while (!Nodes_queue.empty()) {
            int sz = Nodes_queue.size();
            vector<int> v;

            // Traverse nodes at the current level
            while (sz--) {
                TreeNode* cur = Nodes_queue.front();
                Nodes_queue.pop();
                v.push_back(cur->val);

                // Enqueue the left child if it exists
                if (cur->left) {
                    Nodes_queue.push(cur->left);
                }

                // Enqueue the right child if it exists
                if (cur->right) {
                    Nodes_queue.push(cur->right);
                }
            }

            // Step 4: Add the rightmost node value to the result vector
            ans.push_back(v.back());
        }

        // Step 5: Return the right side view vector
        return ans;
    }
};
