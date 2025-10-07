class Solution {
public:
    bool find(vector<vector<bool>>& marked, vector<vector<char>>& board,
              const string& word, int i, int j, int a) {
        if (a >= word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            marked[i][j])
            return false;
        bool a1 = false, a2 = false, a3 = false, a4 = false;
        if (board[i][j] == word[a]) {
            marked[i][j] = true;
            a1 = find(marked, board, word, i - 1, j, a + 1);
            a2 = find(marked, board, word, i + 1, j, a + 1);
            a3 = find(marked, board, word, i, j - 1, a + 1);
            a4 = find(marked, board, word, i, j + 1, a + 1);
            marked[i][j] = false;
        }
        return a1 || a2 || a3 || a4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> marked(m, vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                found = find(marked, board, word, i, j, 0);
                if (found)
                    break;
            }
            if (found)
                break;
        }
        return found;
    }
};