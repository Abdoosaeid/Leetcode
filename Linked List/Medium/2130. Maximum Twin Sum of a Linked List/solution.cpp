class Solution {
public:
    int pairSum(ListNode* head) {
        // Optimize input/output for C++ streams
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        // Initialize a new head for the reversed list
        ListNode* newhead = nullptr;
        ListNode* temp = head; // Save the original head
        int count = 0; // Count the number of nodes in the list

        // Reverse the linked list
        while (head) {
            ListNode* newnode = new ListNode(head->val, newhead);
            newhead = newnode;
            head = head->next;
            count++;
        }

        // Reset the head to the original head
        head = temp;

        int mx = 0; // Variable to store the maximum sum of pairs

        // Iterate over the first half of the list
        for (int i = 0; i < count / 2; ++i) {
            // Calculate the sum of the current pair
            int currentSum = head->val + newhead->val;

            // Update the maximum sum if the current sum is greater
            if (currentSum > mx) {
                mx = currentSum;
            }

            // Move to the next nodes in both the original and reversed lists
            head = head->next;
            newhead = newhead->next;
        }

        // Return the maximum sum of pairs
        return mx;
    }
};
