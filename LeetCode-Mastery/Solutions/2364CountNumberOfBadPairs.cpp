class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;  // Use unordered_map for better performance on average
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - i]++;  // Count the occurrences of (nums[i] - i)
        }

        long long totalPairs = (long long)nums.size() * (nums.size() - 1) / 2;  // Total number of pairs
        long long goodPairs = 0;
        
        // Count good pairs based on (nums[i] - i) frequency
        for (const auto& pair : mp) {
            long long n = pair.second;
            goodPairs += n * (n - 1) / 2;  // Calculate good pairs using combination formula
        }
        
        // Bad pairs = Total pairs - Good pairs
        return totalPairs - goodPairs;
    }
};
