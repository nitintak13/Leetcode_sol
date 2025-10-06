class Solution {
public:
    int dp[201][1001];
    int fun(int ind, int k, vector<int>& nums, int sum) {
        int n = nums.size();

        if (ind >= n) {
            if (sum == k) {
                return 1;
            }
            return 0;
        }
        if (sum > k) {
            return 0;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int left = 0, right = 0;

        if (sum + nums[ind] <= k)
            left += fun(0, k, nums, sum + nums[ind]);
        right += fun(ind + 1, k, nums, sum);

        return dp[ind][sum] = left + right;
    }

    int combinationSum4(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, k, arr, 0);
    }
};