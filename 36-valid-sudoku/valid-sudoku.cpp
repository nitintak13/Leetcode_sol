class Solution {
public:
    bool safe(int r, int c, vector<vector<char>>& board, char k) {
        int cnt = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == k) {
                cnt++;
            }
            if (board[r][i] == k) {
                cnt++;
            }
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k) {
                cnt++;
            }
        }
        return cnt == 3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9, m = 9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    if (!safe(i, j, board, board[i][j])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};