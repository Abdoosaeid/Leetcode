class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int, int> mp; // Hash map to store sums of nums1 and nums2
            int count = 0;
    
            // Step 1: Compute all possible sums of pairs from nums1 and nums2
            // and store the frequency of each sum in the hash map.
            for (const auto& n1 : nums1) {
                for (const auto& n2 : nums2) {
                    mp[n1 + n2]++; // Increment frequency of the sum
                }
            }
    
            // Step 2: Iterate through all pairs from nums3 and nums4
            // and check if the negative of their sum exists in the map.
            for (const auto& n3 : nums3) {
                for (const auto& n4 : nums4) {
                    int target = - (n3 + n4); // We need (n1 + n2) = - (n3 + n4)
                    
                    // Check if this sum exists in the hash map
                    auto it = mp.find(target);
                    if (it != mp.end()) {
                        count += it->second; // Add the frequency of the sum to count
                    }
                }
            }
    
            return count; // Return the final count of valid quadruplets
        }
    };
    