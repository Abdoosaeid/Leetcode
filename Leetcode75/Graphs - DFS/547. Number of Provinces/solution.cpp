class Solution {
public:
    // Define a graph data structure as an unordered map
    // Each node is mapped to a vector containing its adjacent nodes
    typedef unordered_map<int, vector<int>> Graph;

    // Depth-first search function to traverse the graph
    void dfs(int node, Graph &graph, unordered_set<int> &visited) {
        // Mark the current node as visited
        visited.insert(node);

        // Iterate through the adjacent nodes of the current node
        for (int neighbor : graph[node]) {
            // If the neighbor has not been visited, recursively explore it
            if (!visited.count(neighbor)) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    // Function to find the number of connected components in the graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Initialize the count of connected components to 0
        int count = 0;

        // Create an unordered set to keep track of visited nodes
        unordered_set<int> visited;

        // Create an empty graph represented by an unordered map
        Graph graph;

        // Iterate through the adjacency matrix to build the graph
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[0].size(); ++j) {
                // If there is a connection between nodes i and j, add j to the adjacency list of i
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }

        // Iterate through each node in the graph
        for (auto node : graph) {
            // If the node hasn't been visited, it means it belongs to a new connected component
            if (!visited.count(node.first)) {
                // Increment the count of connected components
                count++;
                // Start a depth-first search from the current node to explore the connected component
                dfs(node.first, graph, visited);
            }
        }

        // Return the count of connected components
        return count;
    }
};
