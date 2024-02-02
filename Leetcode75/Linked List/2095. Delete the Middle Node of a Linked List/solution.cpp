
class Solution {
public:
    ListNode* deleteMiddleNode(ListNode* head) {
        // Check if the list has 0 or 1 node, in which case there is no middle to delete
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Initialize two pointers: slowPtr moves one step at a time, fastPtr moves two steps at a time
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        // prevSlowPtr keeps track of the node before the slowPtr
        ListNode* prevSlowPtr = nullptr;

        // Traverse the list until the fastPtr reaches the end
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            // Update prevSlowPtr to the current slowPtr
            prevSlowPtr = slowPtr;
            // Move slowPtr one step forward
            slowPtr = slowPtr->next;
            // Move fastPtr two steps forward
            fastPtr = fastPtr->next->next;
        }

        // Check if the list has an even number of nodes
        if (prevSlowPtr != nullptr) {
            // If even, update the link to skip the middle node
            prevSlowPtr->next = slowPtr->next;
        } else {
            // If odd, update the head to skip the middle node
            head = head->next;
        }

        // Deallocate memory for the middle node
        delete slowPtr;

        // Return the modified head of the list
        return head;
    }
};
