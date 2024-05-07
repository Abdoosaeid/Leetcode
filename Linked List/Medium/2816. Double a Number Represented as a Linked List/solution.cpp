class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Disabling synchronization with standard I/O streams for faster I/O
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        stack<int> st; // Initialize a stack to store values of the input linked list

        // Push values of the input linked list onto the stack
        while (head) {
            st.push(head->val);
            head = head->next;
        }

        int cur = 0; // Initialize a variable to store the carry
        ListNode* result = nullptr; // Initialize a pointer to the result linked list

        // Process the stack and the carry to create the result linked list
        while (!st.empty() || cur) {
            int val = cur; // Initialize val with the current carry
            if (!st.empty()) {
                val += 2 * st.top(); // Add the current value of the stack element, multiplied by 2
                st.pop(); // Pop the top element from the stack
            }
            cur = val / 10; // Calculate the new carry
            val %= 10; // Calculate the new value after handling the carry

            // Create a new node with the calculated value
            ListNode* newNode = new ListNode(val);
            newNode->next = result; // Connect the new node to the result linked list
            result = newNode; // Update the result pointer to the new node
        }

        return result; // Return the pointer to the result linked list
    }
};
