class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        ListNode * temp = head;
        while (temp && temp->next)
        {
            int num1 , num2 ;
            num1 = temp->val;
            num2 = temp->next->val;
            int GCD = gcd(num1,num2);
            ListNode* node = new ListNode(GCD);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        return head;
    }
};