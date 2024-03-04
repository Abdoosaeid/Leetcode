class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Calculate the size of the linked list
        int size = 0;
        ListNode* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }

        // Step 2: If the size is equal to n, remove the head
        if (size == n) {
            head = head->next;
            return head;
        }

        // Step 3: Traverse to the node before the nth node
        int count = size - n - 1;
        temp = head;
        while (count-- && temp->next) {
            temp = temp->next;
        }

        // Step 4: Remove the nth node
        if (temp->next) {
            temp->next = temp->next->next;
        } else {
            temp->next = NULL;
        }

        // Step 5: Return the modified head of the linked list
        return head;
    }
};
