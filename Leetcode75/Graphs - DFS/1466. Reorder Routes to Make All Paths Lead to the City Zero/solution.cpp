// Define a struct for an edge containing the destination node and a boolean indicating if the edge is built or not
struct edge {
    int to;       // Destination node of the edge
    bool built;   // Indicates whether the edge is built (true) or not (false)
};

// Define a typedef for a graph represented as a vector of vectors of edges
typedef vector<vector<edge>> GRAPH;

// Function to add an undirected edge to the graph
void add_undirected_edge(GRAPH &graph, int from, int to) {
    // Add the edge from 'from' to 'to' with 'built' set to true
    graph[from].push_back({to, true});
    // Add the reverse edge from 'to' to 'from' with 'built' set to false
    graph[to].push_back({from, false});
}

// Depth-First Search (DFS) function to traverse the graph
// and count the number of edges that need to be reoriented
void dfs(GRAPH &graph, int node, vector<bool> &visited, int &reorient_cnt) {
    // Mark the current node as visited
    visited[node] = true;

    // Iterate over the edges of the current node
    for (edge &e : graph[node]) {
        // If the destination node of the edge is not visited yet
        if (!visited[e.to]) {
            // Increment the reorientation count if the edge is built
            reorient_cnt += e.built;
            // Recursively call DFS for the destination node
            dfs(graph, e.to, visited, reorient_cnt);
        }
    }
}

// Solution class containing the function to find the minimum reorientation count
class Solution {
public:
    // Function to find the minimum reorientation count given the number of nodes and connections
    int minReorder(int nodes, vector<vector<int>> &connections) {
        // Initialize the reorientation count to 0
        int reorient_cnt = 0;
        // Create a graph with 'nodes' number of nodes
        GRAPH graph(nodes);
        // Initialize a vector to keep track of visited nodes
        vector<bool> visited(nodes);

        // Iterate over the connections and add edges to the graph
        for (auto &edge : connections)
            add_undirected_edge(graph, edge[0], edge[1]);

        // Perform DFS starting from node 0 to count the reorientations
        dfs(graph, 0, visited, reorient_cnt);

        // Return the minimum reorientation count
        return reorient_cnt;
    }
};
