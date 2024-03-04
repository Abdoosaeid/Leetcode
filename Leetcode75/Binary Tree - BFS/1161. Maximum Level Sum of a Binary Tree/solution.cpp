class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // Step 1: Initialize variables
        int sum1 = root->val; // Sum of the root level
        int level = 0;        // Current level
        int ans = 0;          // Answer variable (level with maximum sum)

        // Step 2: Initialize a queue for level-order traversal
        std::queue<TreeNode*> q;
        q.push(root);

        // Step 3: Perform level-order traversal
        while (!q.empty()) {
            int size = q.size();
            int sum2 = 0; // Sum of values at the current level

            // Traverse nodes at the current level
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                sum2 += cur->val;

                // Enqueue the left child if it exists
                if (cur->left) {
                    q.push(cur->left);
                }

                // Enqueue the right child if it exists
                if (cur->right) {
                    q.push(cur->right);
                }
            }

            // Step 4: Update the answer if the current level has a greater sum
            if (sum2 > sum1) {
                ans = level;
                sum1 = sum2;
            }

            // Move to the next level
            level++;
        }

        // Step 5: Return the level with the maximum sum (1-indexed)
        return ans + 1;
    }
};
