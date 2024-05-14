ListNode *detectCycle(ListNode *head) {
    // Optimization for faster I/O operations.
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    // Initialize two pointers, 's' (slow) and 'f' (fast).
    ListNode *s = head, *f = head;

    // Loop until the fast pointer 'f' or its next node is null.
    while (f != NULL && f->next != NULL) {
        // Move slow pointer 's' one step forward.
        s = s->next;
        // Move fast pointer 'f' two steps forward.
        f = f->next->next;

        // Check if the pointers have met, indicating a cycle.
        if (s == f) {
            // If a cycle is detected, move 's' and 'head' one step at a time to find the start of the cycle.
            while (s != head) {
                s = s->next;
                head = head->next;
            }
            // Return the starting node of the cycle.
            return s;
        }
    }
    // If no cycle is found, return NULL.
    return NULL;
}
