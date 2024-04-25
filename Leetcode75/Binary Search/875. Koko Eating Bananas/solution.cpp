class Solution {
public:
    // Function to check if K is feasible
    bool count(vector<int>& v, int h, long long value) {
        long long ans = 0; // Initialize the total hours
        for (int i = 0, sz = v.size(); i < sz; ++i) {
            if (value == 0) return false;  // If K is 0, it's not feasible
            ans += ceil((double)v[i] / value);  // Calculate the hours needed to eat all bananas with K speed
            if (ans > h) return false; // If total hours exceed h, K is not feasible
        }
        return true; // Otherwise, K is feasible
    }

    // Main function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL); // Fast IO
        sort(piles.begin(),piles.end()); // Sort the pile sizes

        // Initialize the search range
        long long l = 0, r = piles[piles.size() - 1], ans = 0;

        // Binary search to find the minimum feasible K
        while (l <= r)
        {
            long long mid = l + (r - l) / 2; // Calculate the middle value

            // Check if the current K is feasible
            if (count(piles, h, mid))
            {
                ans = mid; // Update the answer to the current K
                r = mid - 1; // Update the upper bound of the search range
            }
            else
            {
                l = mid + 1; // Update the lower bound of the search range
            }
        }
        return ans; // Return the minimum feasible K
    }
};
