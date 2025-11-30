class Solution {
public:
    int maxi = 0;
    int dp[100001][2][3];
    int fun(int ind, int buy, int left, vector<int>& prices) {
        int n = prices.size();
        if (ind == n || left == 0)
            return 0;
        if (dp[ind][buy][left] != -1)
            return dp[ind][buy][left];
        int profit = 0;
        if (buy == 0) {
            profit = max(0 + fun(ind + 1, 0, left, prices),
                         -prices[ind] + fun(ind + 1, 1, left, prices));
        }
        if (buy == 1) {
            profit = max(0 + fun(ind + 1, 1, left, prices),
                         prices[ind] + fun(ind + 1, 0, left - 1, prices));
        }
        return dp[ind][buy][left] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, 2, prices);
    }
};