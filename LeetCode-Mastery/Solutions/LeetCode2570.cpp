class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            map<int, int> mp;
            
            // Merging the first array
            for (vector<int> &num : nums1) {
                mp[num[0]] += num[1];
            }
            
            // Merging the second array
            for (vector<int> &num : nums2) {
                mp[num[0]] += num[1];
            }
    
            // Converting map to vector
            vector<vector<int>> answer;
            for (auto &m : mp) {
                answer.push_back({m.first, m.second});
            }
            
            return answer;
        }
    };
    