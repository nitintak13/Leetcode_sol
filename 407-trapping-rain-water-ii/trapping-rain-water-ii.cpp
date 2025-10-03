class Solution {
public:
    using p = pair<int, pair<int, int>>;
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        priority_queue<p, vector<p>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({h[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        long long water = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int len = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    water += max(len - h[nr][nc], 0);
                    pq.push({max(len, h[nr][nc]), {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }
        return (int)water;
    }
};