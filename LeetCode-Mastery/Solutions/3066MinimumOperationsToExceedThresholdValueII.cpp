class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            // Speed up input/output operations
            ios_base::sync_with_stdio(false); 
            cout.tie(NULL); 
            cin.tie(NULL);
    
            // Create a min-heap (priority queue) and initialize it with all elements from nums
            priority_queue <long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
    
            int count = 0; // Counter for the number of operations performed
    
            // Continue until the smallest element in the heap is at least 'k'
            while (true) {
                if (pq.top() >= k) {
                    return count; // If the minimum element is >= k, return the operation count
                }
    
                // Extract the two smallest elements from the heap
                long long x = pq.top();
                pq.pop();
                long long y = pq.top();
                pq.pop();
    
                count++; // Increment the operation count
    
                // Apply the operation: new element = (min(x, y) * 2) + max(x, y)
                pq.push(min(x, y) * 2 + max(x, y));
            }
    
            return count; // This line will never be reached, as the while loop always returns before this
        }
    };
    