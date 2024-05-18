class Solution {
public:
    // Directions for the 4 possible movements: up, right, down, left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Struct to represent a cell in the maze with row and column indices
    struct cell {
        int r, c;
    };

    // Function to check if a cell (r, c) is within the bounds of the maze
    bool isValid(int r, int c, vector<vector<char>>& matrix) {
        if (r < 0 || r >= matrix.size())
            return false;
        if (c < 0 || c >= matrix[0].size())
            return false;
        return true;
    }

    // Function to find the nearest exit from the entrance
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

        queue<cell> q;  // Queue for BFS
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));  // Visited array

        // Start BFS from the entrance
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        // Perform BFS
        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                // Explore all 4 possible directions
                for (int i = 0; i < 4; ++i) {
                    int nr = dr[i] + r, nc = dc[i] + c;

                    // Continue if the cell is out of bounds, is a wall, or is already visited
                    if (!isValid(nr, nc, maze) || maze[nr][nc] == '+' || visited[nr][nc]) {
                        continue;
                    }

                    // Check if it's an exit and it's not the entrance
                    if ((nr == 0 || nc == 0 || nr == maze.size() - 1 || nc == maze[0].size() - 1) &&
                        !(nr == entrance[0] && nc == entrance[1])) {
                        return level + 1;
                    }

                    // Mark the cell as visited and add it to the queue
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return -1; // Return -1 if no exit is found
    }
};
