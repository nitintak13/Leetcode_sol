class Solution {
public:
    int maxi = -1;
    int fun(int ind, vector<int>& nums, int sum, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n) {
            return 0;
        }
        if (ind == n - 1) {
            return nums[ind];
        }
        if (dp[ind] != -1)
            return dp[ind];
        int left = fun(ind + 1, nums, sum, dp);
        int right = nums[ind] + fun(ind + 2, nums, sum, dp);
        return dp[ind] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int num = prev;
            int num2 = nums[i] + prev2;

            dp[i] = max(num2, num);
            prev2 = prev;
            prev = dp[i];
        }
        return prev;
    }
};