class Solution {
public:
    void solve(int ind, int n, int k, vector<vector<int>>& ans, vector<int> res,
               int len) {
        if (len == k) {
            ans.push_back(res);
            return;
        }
        for (int i = ind + 1; i <= n; i++) {
            res.push_back(i);
            solve(i, n, k, ans, res, len+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0, n, k, ans, res, 0);
        return ans;
    }
};