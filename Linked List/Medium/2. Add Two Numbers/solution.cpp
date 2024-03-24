class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a new ListNode to store the result
        ListNode* node = new ListNode();
        // Create a pointer to the head of the result list
        ListNode* head = node;
        // Initialize carry to 0
        int carry = 0;

        // Iterate through both lists until one of them ends or there is a carry
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0;

            // Add values from l1 if it is not NULL
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add values from l2 if it is not NULL
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry from the previous iteration
            sum += carry;
            // Update carry for the next iteration
            carry = sum / 10;
            // Create a new ListNode with the digit sum % 10
            ListNode* newNode = new ListNode(sum % 10);
            // Link the new node to the result list
            head->next = newNode;
            // Move the head pointer to the newly added node
            head = head->next;
        }

        // Return the next node after the initial dummy node
        return node->next;
    }
};
