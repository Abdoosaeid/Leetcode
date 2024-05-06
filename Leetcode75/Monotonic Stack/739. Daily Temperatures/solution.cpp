class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Disabling synchronization with standard I/O streams for faster I/O
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int n = temperatures.size();
        vector<int> ans(n); // Initialize a vector to store the result
        stack<int> st; // Initialize a stack to store indices of temperatures

        // Iterate over the temperatures array in reverse order
        for (int i = n - 1; i >= 0; --i) {
            // While the stack is not empty and the current temperature is greater than or equal to the temperature at the top of the stack
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop(); // Pop temperatures from the stack until a warmer temperature is found
            }

            // If the stack is empty, there are no warmer temperatures ahead
            // Otherwise, calculate the difference in days between the current temperature and the warmer temperature
            ans[i] = st.empty() ? 0 : st.top() - i;

            // Push the index of the current temperature onto the stack
            st.push(i);
        }

        return ans; // Return the result vector
    }
};
