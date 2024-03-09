class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *item1 = head;
        ListNode *item2 = head;

        // Using two pointers to traverse the linked list
        while (item1 && item2 && item2->next) {
            item1 = item1->next;           // Move one step at a time
            item2 = item2->next->next;     // Move two steps at a time
        }

        return item1;  // The middle node is stored in item1
    }
};
