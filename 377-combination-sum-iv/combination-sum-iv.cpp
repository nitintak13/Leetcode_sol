class Solution {
public:
    int f(int t, vector<int>& dp, vector<int>& n) {
        if (t == 0)
            return 1;
        if (dp[t] != -1)
            return dp[t];
        int ans = 0;
        for (int i = 0; i < n.size(); i++) {
            if (t - n[i] < 0)
                break;
            ans = ans + f(t - n[i], dp, n);
        }
        return dp[t] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1001, -1);
        return f(target, dp, nums);
    }
};