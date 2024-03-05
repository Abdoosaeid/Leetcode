class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is null, or either p or q is found, return the root
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recursively search for the LCA in the left and right subtrees
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // If both p and q are found in different subtrees, the current root is the LCA
        if (l && r) {
            return root;
        }

        // If either l or r is not null, return the non-null value
        return l ? l : r;
    }
};
