class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n + 1, 0);
        dp[0] = energy[0];
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) {
                dp[i] = max(energy[i] + dp[i - k], energy[i]);
            } else {
                dp[i] = energy[i];
            }
        }
        int ans = INT_MIN;
        for (int i = n - 1; i >= n - k; i--) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};