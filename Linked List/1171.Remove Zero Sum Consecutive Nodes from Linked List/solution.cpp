class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a hash map to store the running sum and corresponding node
        unordered_map<int, ListNode*> mp;

        // Create a dummy node and initialize the map with a sum of 0
        ListNode node = ListNode(0, head);
        mp[0] = &node;

        ListNode *item = head;
        int sum = 0;

        // Traverse the linked list to calculate the running sum and store in the map
        while (item) {
            sum += item->val;
            mp[sum] = item;
            item = item->next;
        }

        sum = 0;

        // Traverse the linked list again to update next pointers
        for (ListNode* ptr = &node; ptr; ptr = ptr->next) {
            sum += ptr->val;
            ptr->next = mp[sum]->next;
        }

        return node.next;  // Return the modified linked list
    }
};
