class Solution {
public:
    // DFS function to extract leaf values and store them in the vector
    void dfs(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        if (!root->right && !root->left) {
            v.push_back(root->val);
        }
        dfs(root->right, v);
        dfs(root->left, v);
    }

    // Main function to check if leaf sequences are similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Initialize vectors to store leaf values for both trees
        vector<int> v1, v2;

        // Extract leaf values using DFS for both trees
        dfs(root1, v1);
        dfs(root2, v2);

        // Compare the leaf sequences
        return v1 == v2;
    }
};
