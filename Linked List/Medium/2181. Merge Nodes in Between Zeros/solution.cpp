class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Dummy node to handle edge cases and simplify the return statement
        ListNode *dummy = new ListNode(0);
        // Pointer to traverse and build the new list
        ListNode *temp2 = dummy;

        // Skip the first zero node
        head = head->next;

        // Variable to accumulate the sum of node values between zeros
        long long sum = 0;

        // Traverse the original list
        while (head) {
            if (head->val == 0) {
                // When a zero node is encountered, create a new node with the accumulated sum
                temp2->next = new ListNode(sum);
                // Move temp2 to the newly created node
                temp2 = temp2->next;
                // Reset sum to 0 for the next segment
                sum = 0;
            } else {
                // Add current node's value to sum
                sum += head->val;
            }
            // Move to the next node in the original list
            head = head->next;
        }

        // Return the next node of dummy, which points to the head of the newly created merged list
        return dummy->next;
    }
};