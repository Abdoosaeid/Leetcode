class Solution {
public:
    int count = 0;

    // Recursive helper function to traverse the tree and count valid paths
    void help(TreeNode* root, int targetSum, long long sum) {
        if (!root) {
            return;
        }

        // Update the current sum
        sum += root->val;

        // Check if the current sum equals the targetSum
        if (sum == targetSum) {
            count++;
        }

        // Recursively explore left and right subtrees
        help(root->left, targetSum, sum);
        help(root->right, targetSum, sum);
    }

    // Main function to calculate the number of paths with the given targetSum
    int pathSum(TreeNode* root, long long targetSum) {
        if (!root) {
            return 0;
        }

        // Call the recursive helper function
        help(root, targetSum, 0);

        // Recursively explore left and right subtrees
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        // Return the total count of valid paths
        return count;
    }
};
