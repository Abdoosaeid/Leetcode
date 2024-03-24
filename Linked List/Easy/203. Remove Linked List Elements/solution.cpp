class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Check if the head of the list is NULL, indicating an empty list
        if (head == NULL) {
            return NULL; // Return NULL as there are no elements to remove
        }

        // Initialize a pointer 'item' to traverse the list starting from the head
        ListNode *item = head;

        // Iterate through the list until 'item' is not NULL and 'item->next' is not NULL
        while (item && item->next) {
            // If the next node's value is equal to the target value 'val'
            if (item->next->val == val) {
                // Remove the next node by skipping it in the list
                item->next = item->next->next;
            } else {
                // Move to the next node in the list
                item = item->next;
            }
        }

        // Check if the last node's value is equal to the target value 'val'
        if (item && item->val == val) {
            item = NULL; // Remove the last node by setting it to NULL
        }

        // Check if the value of the head node is equal to the target value 'val'
        if (head->val == val) {
            head = head->next; // Update the head to point to the next node
        }

        // Return the updated head of the list
        return head;
    }
};
