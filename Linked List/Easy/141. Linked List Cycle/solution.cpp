class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers: slow pointer (s) and fast pointer (f) to the head of the list
        ListNode *s = head, *f = head;

        // Loop until the fast pointer (f) reaches the end of the list or encounters a cycle
        while (f != NULL && f->next != NULL) {
            // Move the slow pointer (s) one step forward
            s = s->next;
            // Move the fast pointer (f) two steps forward
            f = f->next->next;

            // If the slow pointer (s) meets the fast pointer (f), indicating a cycle
            if (s == f) {
                return true; // Return true (the list has a cycle)
            }
        }

        // If the loop exits, it means either the fast pointer (f) reached the end of the list or encountered a cycle
        // In both cases, return false (no cycle detected)
        return false;
    }
};
