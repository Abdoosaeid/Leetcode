class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize two pointers: prev is initially NULL, and cur points to the head of the list
        ListNode* prev = NULL;
        ListNode* cur = head;

        // Traverse the list
        while (cur != NULL) {
            // Save the next node in the list to avoid losing it during reversal
            ListNode* nxt = cur->next;
            // Reverse the link to point backward
            cur->next = prev;
            // Move the prev pointer to the current node
            prev = cur;
            // Move the cur pointer to the next node
            cur = nxt;
        }

        // 'prev' is now pointing to the new head of the reversed list
        return prev;
    }
};
