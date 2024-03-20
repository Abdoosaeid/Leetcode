class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Pointer to traverse through list1
        ListNode *item = list1;
        // Pointers to keep track of the nodes before and after the sublist to be replaced
        ListNode *first, *last;
        // Variable to count the current index while traversing list1
        int count = 1;

        // Traverse list1 to find the nodes before and after the sublist to be replaced
        while (item->next && count <= b + 1) {
            // If current index matches 'a', assign the current node to 'first'
            if (count == a)
                first = item;
            // If current index matches 'b + 1', assign the next node to 'last'
            if (count - 1 == b)
                last = item->next;
            // Move to the next node
            item = item->next;
            // Increment the index counter
            count++;
        }

        // Link the 'first' node to the head of 'list2', effectively replacing the sublist
        first->next = list2;

        // Pointer to traverse through list2 to find its last node
        ListNode *item2 = list2;
        // Iterate through list2 until the last node
        while (item2->next) {
            item2 = item2->next;
        }

        // Link the last node of list2 to the node 'last', connecting the rest of list1
        item2->next = last;

        // Return the head of the modified list1
        return list1;
    }
};
