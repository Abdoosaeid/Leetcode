class Solution {
public:
    // Function to sort characters in the string based on their frequency
    string frequencySort(string s) {
        // Map to store character frequency
        map<char, int> mp;

        // Count the frequency of each character
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            mp[s[i]]++;
        }

        // Priority queue to store pairs of characters and their frequencies
        // The priority queue is configured to pop the pair with higher frequency first
        priority_queue<pair<int, char>> pq;

        // Fill the priority queue with pairs
        for (auto m : mp) {
            pq.push({m.second, m.first});
        }

        // Result string
        string ans = "";

        // Build the result string based on the sorted character frequencies
        while (!pq.empty()) {
            int n = pq.top().first;  // Frequency of the character
            while (n--) {
                ans += pq.top().second;  // Append the character to the result string
            }
            pq.pop();  // Remove the processed pair from the priority queue
        }

        return ans;
    }
};
