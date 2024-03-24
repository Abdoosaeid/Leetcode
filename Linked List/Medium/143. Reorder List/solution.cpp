class Solution {
public:
    void reorderList(ListNode* head) {
        // Declare a deque to store the values of the nodes
        deque<int> dq;
        // Traverse the linked list and store the values in the deque
        ListNode* item = head;
        while (item) {
            dq.push_back(item->val);
            item = item->next;
        }

        // Boolean flag to alternate between adding values from front and back of the deque
        bool flag = true;
        // Traverse the linked list again to update the values
        item = head;
        while (item) {
            // If flag is true, add the front value of the deque to the current node's value
            if (flag) {
                item->val = dq.front();
                dq.pop_front();
                flag = false;
            }
                // If flag is false, add the back value of the deque to the current node's value
            else {
                item->val = dq.back();
                dq.pop_back();
                flag = true;
            }
            // Move to the next node
            item = item->next;
        }
    }
};
