class Solution {
public:
    int fun(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        string p = "";
        int val = 0;
        for (int j = i; j < n; j++) {
            p += s[j];
            if (stoi(p) <= 0 || stoi(p) > 26)
                break;
            val += fun(j + 1, s, dp);
        }
        return dp[i] = val;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return fun(0, s, dp);
    }
};