class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the root is null or the value is found
        if (!root || root->val == val) {
            return root;
        }

        // Recursive search in the left subtree if the value is smaller
        if (root->val > val) {
            return searchBST(root->left, val);
        }
            // Recursive search in the right subtree if the value is larger
        else {
            return searchBST(root->right, val);
        }
    }
};
