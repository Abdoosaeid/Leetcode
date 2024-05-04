class Solution {
public:
    // Map to represent relationships between variables.
    unordered_map<string, vector<pair<string, double>>> graph;

    // Depth-First Search (DFS) to find division value between two variables.
    void dfs(string a, string b, unordered_map<string, bool>& visited, double temp, double& ans) {
        // If either variable is visited or answer is already found, return.
        if (visited[a] || ans != -1.0) {
            return;
        }
        // If we reach the destination variable, update the answer and return.
        if (a == b) {
            ans = temp;
            return;
        }
        // Mark the current variable as visited.
        visited[a] = true;
        // Explore neighbors of the current variable.
        for (auto& i : graph[a]) {
            dfs(i.first, b, visited, temp * i.second, ans);
        }
    }

    // Function to evaluate division based on provided equations and values.
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        // Building the graph from equations and values.
        int k = 0;
        for (auto& x : equations) {
            string a = x[0];
            string b = x[1];
            // Adding entries to the graph for each equation and its inverse.
            graph[a].push_back({b, values[k]});
            graph[b].push_back({a, 1.0 / values[k]});
            k++;
        }

        // Vector to store the results for each query.
        vector<double> ans;
        // Processing each query.
        for (auto& x : queries) {
            string a = x[0];
            string b = x[1];
            unordered_map<string, bool> visited;
            // If the source variable doesn't exist in the graph, add -1.0 to the results.
            if (graph.find(a) == graph.end()) {
                ans.push_back(-1.0);
                continue;
            }
            double ans2 = -1.0;
            double temp = 1.0;
            // Perform DFS to find division value between variables.
            dfs(a, b, visited, temp, ans2);
            // Store the result for the current query.
            ans.push_back(ans2);
        }
        // Return the results for all queries.
        return ans;
    }
};

