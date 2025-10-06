typedef pair<int, pair<int, int>> p;
class Solution {

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dist = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            if (x == n - 1 && y == n - 1) {
                return dist;
            }
            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, -1, 0, 1};
            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !visited[nx][ny]) {
                    // int diff = grid[nx][ny] - grid[x][y];
                    visited[nx][ny] = true;

                    pq.push({max(dist, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        return -1;
    }
};