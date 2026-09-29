class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                   int color) {
        int n = image.size();
        int m = image[0].size();

        int val = image[sr][sc];

        // If same color, nothing to do
        if (val == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Mark as soon as we push
        image[sr][sc] = color;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (image[nx][ny] == val) {

                        // Mark BEFORE pushing
                        image[nx][ny] = color;

                        q.push({nx, ny});
                    }
                }
            }
        }

        return image;
    }
};