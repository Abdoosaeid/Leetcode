class Solution {
public:
    // Recursive function to find the number of good nodes
    int good(TreeNode* root, int mx) {
        if (!root) {
            return 0;
        }
        // Check if the current node is a good node
        int ans = mx <= root->val;

        // Recursive calls for left and right subtrees
        int l = good(root->left, max(mx, root->val));
        int r = good(root->right, max(mx, root->val));

        // Total number of good nodes in the subtree rooted at the current node
        return l + r + ans;
    }

    // Main function to calculate the number of good nodes
    int goodNodes(TreeNode* root) {
        // Call the recursive function with the initial maximum value set to the root's value
        return good(root, root->val);
    }
};
