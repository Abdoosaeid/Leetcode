/*
* Author: Abdoo__said
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify code
        ListNode node(0);
        ListNode* head = &node;

        // Iterate until one of the lists becomes empty
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                // Connect the current node to the smaller value node
                head->next = list1;
                // Move head and list1 to the next nodes
                head = list1;
                list1 = list1->next;
            } else {
                // Connect the current node to the smaller value node
                head->next = list2;
                // Move head and list2 to the next nodes
                head = list2;
                list2 = list2->next;
            }
        }

        // Check if any list is remaining and connect it to the result
        if (list1 != NULL) {
            head->next = list1;
        }
        if (list2 != NULL) {
            head->next = list2;
        }

        // Return the merged list starting from the next of the dummy node
        return node.next;
    }
};
