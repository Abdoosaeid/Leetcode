class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Check if the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return head; // No modification needed for a list with 0 or 1 nodes
        }

        // Initialize pointers for odd and even nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        // Save the head of the even list to link it back later
        ListNode* evenHead = even;

        // Traverse the list, connecting odd and even nodes
        while (even != nullptr && even->next != nullptr) {
            // Skip the next odd node by linking even to the one after the next odd node
            even->next = even->next->next;
            // Move to the next even node
            even = even->next;
            // Move to the next odd node
            odd = odd->next;
        }

        // Connect the last odd node to the head of the even list
        odd->next = evenHead;

        // Return the modified head of the list
        return head;
    }
};
