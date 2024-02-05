class RecentCounter {
public:
    // Deque to store recent ping times
    std::deque<int> dq;

    // Constructor
    RecentCounter() {
    }

    // Function to handle a ping and return the number of valid pings within the last 3000 milliseconds
    int ping(int t) {
        // Calculate the time limit for valid pings
        int limit = t - 3000;

        // Push the current ping time onto the deque
        dq.push_back(t);

        // Remove pings that are older than the time limit from the front of the deque
        while (!dq.empty() && dq.front() < limit) {
            dq.pop_front();
        }

        // Return the number of valid pings within the last 3000 milliseconds
        return dq.size();
    }
};
