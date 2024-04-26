class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        sort(potions.begin(), potions.end()); // Sort the potions vector
        vector<int> ans;
        for(int i = 0, sz = spells.size(); i < sz; i++) {
            int l = 0, r = potions.size() - 1; // Initialize left and right pointers for binary search
            while (l <= r) {
                int mid = l + (r - l) / 2; // Calculate the middle index
                // Check if the product of the current potion and spell is greater than or equal to success
                if ((long long)potions[mid] * spells[i] >= success) {
                    r = mid - 1; // If so, update the right pointer
                } else {
                    l = mid + 1; // Otherwise, update the left pointer
                }
            }
            // Push the count of successful pairs into the answer vector
            ans.push_back(potions.size() - l);
        }
        return ans;
    }
};
