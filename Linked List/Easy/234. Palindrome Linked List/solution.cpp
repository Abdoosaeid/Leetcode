class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Initialize an empty string to store the values of the linked list
        string s1 = "";

        // Traverse the linked list and concatenate the values to the string
        while (head) {
            s1 += (head->val + '0'); // Convert integer to character and append to the string
            head = head->next;
        }

        // Create a copy of the original string
        string s2 = s1;

        // Reverse the original string
        reverse(s1.begin(), s1.end());

        // Check if the reversed string is equal to the original string
        if (s1 == s2) {
            return true; // The linked list is a palindrome
        }

        return false; // The linked list is not a palindrome
    }
};
