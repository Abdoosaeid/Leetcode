class Solution {
public:
    // Depth-First Search (DFS) function to traverse the rooms and mark them as visited
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited) {
        // Mark the current room as visited
        visited[node] = true;

        // Iterate over the keys in the current room
        for (int &i : rooms[node]) {
            // If the room corresponding to the key hasn't been visited yet, recursively visit it
            if (!visited[i])
                dfs(i, rooms, visited);
        }
    }

    // Function to check if all rooms can be visited starting from room 0
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Disable synchronization with the C standard streams for faster I/O
        ios_base::sync_with_stdio(false);
        // Untie cin and cout from stdio streams for faster I/O
        cout.tie(NULL);
        cin.tie(NULL);

        // Initialize a vector to keep track of visited rooms, initially all set to false
        vector<bool> visited(rooms.size(), false);

        // Perform DFS starting from room 0
        dfs(0, rooms, visited);

        // Check if all rooms have been visited
        for (bool i : visited) {
            if (i == false) {
                // If any room remains unvisited, return false
                return false;
            }
        }

        // If all rooms have been visited, return true
        return true;
    }
};
