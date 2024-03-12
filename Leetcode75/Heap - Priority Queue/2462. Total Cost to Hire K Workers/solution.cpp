class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;

        // Min-heap priority queues to store elements from the beginning and end of the costs vector
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int cnt = 0;
        int i = 0;
        int j = costs.size() - 1;

        // Iterate until cnt reaches k
        while (cnt < k) {

            // Fill priority queue 1 (pq1) with up to 'candidates' elements from the beginning
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }

            // Fill priority queue 2 (pq2) with up to 'candidates' elements from the end
            while (pq2.size() < candidates && j >= i) {
                pq2.push(costs[j--]);
            }

            // Determine the cost from the top of both priority queues
            int cost1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int cost2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            // Add the minimum cost to the answer and pop the corresponding element from the priority queue
            if (cost1 <= cost2) {
                ans += cost1;
                pq1.pop();
            } else {
                ans += cost2;
                pq2.pop();
            }

            // Increment the counter
            cnt++;
        }

        return ans;
    }
};
