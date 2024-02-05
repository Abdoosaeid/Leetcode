class Solution {
public:
    // Function to simulate asteroid collisions
    vector<int> asteroidCollision(vector<int>& a) {
        // Stack to simulate the asteroid collisions
        stack<int> st;

        // Loop through the asteroid array
        for (int i = 0, sz = a.size(); i < sz; ++i) {
            // If the stack is empty, or the current asteroid is positive, or both asteroids have the same direction
            if (st.empty() || a[i] > 0 || (st.top() < 0 && a[i] < 0)) {
                st.push(a[i]);
                continue;
            } else {
                // Asteroid collision handling
                if (a[i] + st.top() == 0) {
                    // Both asteroids annihilate each other
                    st.pop();
                    continue;
                } else if (st.top() + a[i] > 0) {
                    // Current asteroid is destroyed
                    continue;
                } else {
                    int flag = 1;
                    // Keep destroying asteroids with opposite directions
                    while (!st.empty() && (st.top() + a[i] <= 0 && st.top() > 0)) {
                        if (a[i] + st.top() == 0) {
                            flag = 0;
                            st.pop();
                            break;
                        }
                        st.pop();
                    }

                    // If the stack is empty and the current asteroid is still positive, or push it onto the stack
                    if (st.empty() && flag) {
                        st.push(a[i]);
                        continue;
                    }

                    // If the stack is not empty and the current asteroid is positive, push it onto the stack
                    if (!st.empty() && flag && st.top() + a[i] < 0) {
                        st.push(a[i]);
                    }
                }
            }
        }

        // Vector to store the result of surviving asteroids
        vector<int> ans;

        // Reconstruct the result by popping elements from the stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse the result vector to get the correct order
        reverse(ans.begin(), ans.end());

        // Return the final result
        return ans;
    }
};
