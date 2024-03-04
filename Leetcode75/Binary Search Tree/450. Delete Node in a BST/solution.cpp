class Solution {
public:
    TreeNode* FindMax(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        else if (node->right == nullptr)
            return node;
        else {
            return FindMax(node->right);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Step 1: Call the Delete function to delete the node with the given key
        root = Delete(root, key);
        return root;
    }

    TreeNode* Delete(TreeNode* node, int key) {
        // Step 2: Base case: If the node is nullptr, return nullptr
        if (node == nullptr)
            return nullptr;

        // Step 3: Compare the key with the current node's value
        if (key < node->val)
            node->left = Delete(node->left, key); // Recur on the left subtree
        else if (key > node->val)
            node->right = Delete(node->right, key); // Recur on the right subtree
        else {
            // Step 4: Node to be deleted is found
            if (!node->right && !node->left) {
                // Case 1: Leaf node, delete and return nullptr
                delete node;
                return nullptr;
            } else if (node->left && !node->right) {
                // Case 2: One child on the left
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else if (!node->left && node->right) {
                // Case 3: One child on the right
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else {
                // Case 4: Two children
                TreeNode* max = FindMax(node->left);
                node->val = max->val;
                node->left = Delete(node->left, max->val);
            }
        }
        return node;
    }
};
