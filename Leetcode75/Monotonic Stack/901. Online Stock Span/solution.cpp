class StockSpanner {
public:
    stack<pair<int,int>> st; // Stack to store pairs of price and span

    StockSpanner() {
        // Constructor - disabling synchronization with standard I/O streams for faster I/O
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
    }

    int next(int price) {
        int span = 1; // Initialize span to 1

        // While the stack is not empty and the price of the current day is greater than or equal to the price on top of the stack
        while (!st.empty() && st.top().first <= price) {
            // Add the span corresponding to the price on top of the stack to the current span
            span += st.top().second;
            // Pop the pair from the stack
            st.pop();
        }

        // Push the current price and its corresponding span onto the stack
        st.push({price, span});

        // Return the calculated span for the current day
        return span;
    }
};
