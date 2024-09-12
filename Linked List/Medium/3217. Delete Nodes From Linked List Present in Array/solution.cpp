class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        set<int> s(nums.begin(), nums.end());
        if (!head) return nullptr;
        while (head && s.count(head->val)) {
            head = head->next;
        }
        ListNode* current = head;
        while (current && current->next) {
            if (s.count(current->next->val)) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
