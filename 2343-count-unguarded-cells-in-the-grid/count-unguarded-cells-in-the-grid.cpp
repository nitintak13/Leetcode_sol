class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (auto it : guards) {
            grid[it[0]][it[1]] = 5;
            vis[it[0]][it[1]] = 1;
        }
        for (auto it : walls) {
            grid[it[0]][it[1]] = 5;
            vis[it[0]][it[1]] = 1;
        }
        for (auto& it : guards) {
            int x = it[0];
            int y = it[1];

            // Move right
            for (int i = y + 1; i < n; i++) {
                if (grid[x][i] == 5)
                    break; // Stop at guard or wall
                vis[x][i] = 1;
            }

            // Move left
            for (int i = y - 1; i >= 0; i--) {
                if (grid[x][i] == 5)
                    break; // Stop at guard or wall
                vis[x][i] = 1;
            }

            // Move down
            for (int i = x + 1; i < m; i++) {
                if (grid[i][y] == 5)
                    break; // Stop at guard or wall
                vis[i][y] = 1;
            }

            // Move up
            for (int i = x - 1; i >= 0; i--) {
                if (grid[i][y] == 5)
                    break; // Stop at guard or wall
                vis[i][y] = 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};