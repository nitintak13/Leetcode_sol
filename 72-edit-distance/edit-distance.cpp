class Solution {
public:
    int fun(int i, int j, string word1, string word2, vector<vector<int>>& dp) {
        int n = word1.size();
        int m = word2.size();
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int sum = 0;
        if (word1[i] == word2[j]) {
            sum = fun(i - 1, j - 1, word1, word2, dp);
        } else {
            // insert
            sum = 1 + min({fun(i, j - 1, word1, word2, dp),
                           fun(i - 1, j, word1, word2, dp),
                           fun(i - 1, j - 1, word1, word2, dp)});
        }
        return dp[i][j] = sum;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0 && m == 0)
            return 0;
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(n - 1, m - 1, word1, word2, dp);
    }
};