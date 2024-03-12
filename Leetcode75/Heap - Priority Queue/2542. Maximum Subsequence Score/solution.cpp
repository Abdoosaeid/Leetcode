class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Create a vector of pairs to store pairs (nums2[i], nums1[i])
        vector<pair<int, int>> vp;

        // Populate the vector of pairs
        for (int i = 0, sz = nums1.size(); i < sz; ++i) {
            vp.push_back({nums2[i], nums1[i]});
        }

        // Sort the vector of pairs in descending order based on nums2 values
        sort(vp.rbegin(), vp.rend());

        // Create a min-heap priority queue to store nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long ans = 0, sum = 0;

        // Iterate through the vector of pairs
        for (int i = 0; i < nums1.size(); ++i) {
            sum += vp[i].second;
            pq.push(vp[i].second);

            // Check if the size of the priority queue exceeds k
            if (k < pq.size()) {
                continue;
            } else if (k == pq.size()) {
                // Update the maximum score if necessary
                ans = max(ans, sum * vp[i].first);

                // Adjust the sum and priority queue
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
