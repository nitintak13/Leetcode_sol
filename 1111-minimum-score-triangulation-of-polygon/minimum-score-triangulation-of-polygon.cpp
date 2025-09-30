class Solution {
public:
    int dp[51][51];
    int fun(int i, int j, vector<int>& values) {
        if (j - i + 1 < 3) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            res =
                min(res, fun(i, k, values) + values[i] * values[j] * values[k] +
                             fun(k, j, values));
        }
        return dp[i][j] = res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, n - 1, values);
    }
};