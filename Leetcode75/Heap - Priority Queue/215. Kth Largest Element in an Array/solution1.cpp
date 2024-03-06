class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a max heap (priority queue) using the elements of nums
        priority_queue<int> pq(nums.begin(), nums.end());

        // Remove k-1 largest elements from the max heap
        while (--k > 0) {
            pq.pop();
        }

        // Return the kth largest element, which is now the top of the max heap
        return pq.top();
    }
};
