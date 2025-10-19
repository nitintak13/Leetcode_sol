class Solution {
public:
    int cnt = 0;
    int recsion(int n, vector<int> &dp) {
       if (n == 0 || n == 1) {
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=recsion(n-1,dp)+recsion(n-2,dp);
    }
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1,-1);
        return recsion(n, dp);
       
    }
};