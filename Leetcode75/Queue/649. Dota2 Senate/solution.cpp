class Solution {
public:
    string predictPartyVictory(string senate) {
        // Deques to store indices of active senators from both parties
        deque<int> R_q, D_q;
        // Variable to represent the index assigned to new senators
        int sz = senate.size();

        // Loop through the senate string to initialize the deques
        for (int i = 0; i < sz; i++) {
            if (senate[i] == 'R') {
                R_q.push_back(i);
            } else {
                D_q.push_back(i);
            }
        }

        // Continue the process until one of the parties has no active senators left
        while (!R_q.empty() && !D_q.empty()) {
            // Compare indices of the front senators from both parties
            if (R_q.front() < D_q.front()) {
                // Republican senator targets Democrat senator for evacuation
                D_q.pop_front();
                R_q.pop_front();
                R_q.push_back(sz);
            } else {
                // Democrat senator targets Republican senator for evacuation
                R_q.pop_front();
                D_q.pop_front();
                D_q.push_back(sz);
            }
            // Assign a new index to senators who join the queue after getting evacuated
            sz++;
        }

        // Determine the winning party based on which deque is non-empty
        string ans;
        if (R_q.empty()) {
            ans = "Dire";
        } else {
            ans = "Radiant";
        }

        return ans;
    }
};
