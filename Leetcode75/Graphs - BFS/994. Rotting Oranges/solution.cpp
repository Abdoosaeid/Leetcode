class Solution {
public:
    // Directions for the 4 possible movements: up, right, down, left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Struct to represent a cell in the grid with row and column indices
    struct cell {
        int r, c;
    };

    // Function to check if a cell (r, c) is within the bounds of the matrix
    bool isValid(int r, int c, vector<vector<int>>& matrix) {
        if (r < 0 || r >= matrix.size())
            return false;
        if (c < 0 || c >= matrix[0].size())
            return false;
        return true;
    }

    // BFS function to spread the rotting effect and compute the time needed
    void BFS(vector<vector<int>>& matrix, int &ans) {
        queue<cell> q;

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // If there are no rotten oranges, no time is needed
        if (q.empty()) {
            ans = 0;
            return;
        }

        int level = 0; // Tracks the number of levels (minutes) in BFS

        // Perform BFS
        for (int sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                // Explore all 4 possible directions
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];

                    // Continue if the cell is out of bounds or is empty or already rotten
                    if (!isValid(nr, nc, matrix) || matrix[nr][nc] == 0 || matrix[nr][nc] == 2) {
                        continue;
                    }

                    // If the cell has a fresh orange, rot it and push it into the queue
                    if (matrix[nr][nc] == 1) {
                        matrix[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        // Set the answer to the number of levels minus one
        ans = level - 1;
    }

    // Main function to calculate the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
        int ans = 0;
        BFS(grid, ans);

        // Check if any fresh orange is still left in the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1; // Return -1 if there is any fresh orange left
                }
            }
        }
        return ans; // Return the time needed to rot all oranges
    }
};
