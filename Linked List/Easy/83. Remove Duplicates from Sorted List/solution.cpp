class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head; // No need to swap pairs
        }

        // Initialize a pointer to traverse the list
        ListNode *item = head;

        // Traverse the list while there are at least two nodes ahead
        while (item && item->next) {
            // Swap the values of the current node and its next node
            int value = item->val; // Store the value of the current node
            item->val = item->next->val; // Assign the value of the next node to the current node
            item->next->val = value; // Assign the stored value to the next node
            // Move to the next pair of nodes (two nodes ahead)
            item = item->next->next;
        }

        // Return the head of the modified list
        return head;
    }
};
