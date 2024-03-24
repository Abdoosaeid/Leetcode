class Solution {
public:
    void deleteNode(ListNode* node) {
        // Start traversal from the given node
        ListNode* item = node;
        // Keep track of the previous node to update its next pointer
        ListNode* prev = node;

        // Traverse until the end of the list
        while (item->next) {
            // Move the value of the next node to the current node
            item->val = item->next->val;
            // Update the previous node
            prev = item;
            // Move to the next node
            item = item->next;
        }

        // Once at the end of the list, set the next pointer of the previous node to NULL
        prev->next = NULL;
    }
};
