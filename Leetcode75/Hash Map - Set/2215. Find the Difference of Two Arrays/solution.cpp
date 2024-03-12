class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create unordered sets from nums1 and nums2
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Initialize vectors to store the differences
        vector<int> ans1, ans2;

        // Find elements present in set1 but not in set2
        for (auto &i : set1) {
            if (set2.count(i) == 0) {
                ans1.push_back(i);
            }
        }

        // Find elements present in set2 but not in set1
        for (auto &i : set2) {
            if (set1.count(i) == 0) {
                ans2.push_back(i);
            }
        }

        // Return a vector of vectors containing the differences
        return {ans1, ans2};
    }
};
