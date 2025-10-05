class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        int n = s.size();

        if (s.empty() || s[n - 1] != '0')
            return false;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i >= mini) {
                sum += dp[i - mini];
            }
            if (i > maxi) {
                sum -= dp[i - maxi - 1];
            }
            if (sum > 0 && s[i] == '0') {
                dp[i] = 1;
            }
        }
        return dp[n - 1] == 1;
    }
};