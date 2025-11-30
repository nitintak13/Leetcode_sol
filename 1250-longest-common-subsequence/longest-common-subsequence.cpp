class Solution {
public:
    int fun(int ind1, int ind2, string t1, string t2) {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        int match = 0, nmatch = 0;
        if (t1[ind1] == t2[ind2]) {
            match = 1 + fun(ind1 - 1, ind2 - 1, t1, t2);
        } else {
            nmatch =
                max(fun(ind1 - 1, ind2, t1, t2), fun(ind1, ind2 - 1, t1, t2));
        }

        return max(match, nmatch);
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();

        // dp[i][j] = length of LCS of t1[0..i-1] and t2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

      
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};