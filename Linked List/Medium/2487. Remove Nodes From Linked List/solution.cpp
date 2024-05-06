class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // If the linked list is empty or has only one node, return it as it is
        if (!head || !head->next)
            return head;

        // Use a deque to store the nodes in non-decreasing order
        deque<ListNode*> q;

        // Traverse the linked list and add nodes to the deque while maintaining non-decreasing order
        ListNode *temp = head;
        while (temp) {
            // Remove nodes from the back of the deque if they have greater value than the current node
            while (!q.empty() && temp->val > q.back()->val) {
                q.pop_back();
            }
            // Add the current node to the deque
            q.push_back(temp);
            temp = temp->next;
        }

        // Reconstruct the linked list using nodes from the deque
        head = q.front(); // Set the head of the linked list to the first node in the deque
        temp = head; // Set a temporary pointer to the head

        q.pop_front(); // Remove the first node from the deque (as it is already set as head)

        // Traverse the remaining nodes in the deque and set them as next nodes in the linked list
        while (!q.empty()) {
            temp->next = q.front(); // Set the next node of temp to the front node of the deque
            temp = temp->next; // Move temp to the next node
            q.pop_front(); // Remove the front node from the deque
        }

        // Return the head of the modified linked list
        return head;
    }
};
