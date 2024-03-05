class Solution {
public:
    int ans = 0;

    // Recursive helper function to traverse the tree and calculate zigzag path lengths
    void help(TreeNode* root, int f, int count) {
        if (!root) {
            ans = max(ans, count);
            return;
        }

        // f is the direction flag: -1 for left, 1 for right
        if (!f) {
            help(root->left, -1, count + 1);
            help(root->right, 1, count + 1);
        } else {
            if (f == -1) {
                help(root->left, -1, 1);
                help(root->right, 1, count + 1);
            } else {
                help(root->left, -1, count + 1);
                help(root->right, 1, 1);
            }
        }
    }

    // Main function to calculate the length of the longest zigzag path
    int longestZigZag(TreeNode* root) {
        help(root, 0, 0);
        return ans - 1;
    }
};
