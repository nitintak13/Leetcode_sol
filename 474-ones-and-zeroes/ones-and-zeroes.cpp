class Solution {
public:
    int dp[601][101][101];
    int fun(int ind, int m, int k, vector<string>& strs,
            unordered_map<int, pair<int, int>>& mp) {
        if (ind < 0)
            return 0;
        if (dp[ind][m][k] != -1)
            return dp[ind][m][k];
        int npick = fun(ind - 1, m, k, strs, mp);
        int pick = 0;
        pair<int, int> temp = mp[ind];
        if (temp.first <= m && temp.second <= k) {
            pick = 1 + fun(ind - 1, m - temp.first, k - temp.second, strs, mp);
        }
        return dp[ind][m][k] = max(npick, pick);
    }
    int findMaxForm(vector<string>& strs, int m, int k) {
        int n = strs.size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            int p = strs[i].size();
            int cnt0 = 0, cnt1 = 0;
            for (int j = 0; j < p; j++) {
                if (strs[i][j] == '0') {
                    cnt0++;
                } else {
                    cnt1++;
                }
            }
            mp[i] = {cnt0, cnt1};
        }
        memset(dp, -1, sizeof(dp));
        return fun(n - 1, m, k, strs, mp);
    }
};