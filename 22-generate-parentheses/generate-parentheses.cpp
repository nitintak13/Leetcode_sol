class Solution {
public:
    vector<string> res;
    void fun(int n, int ind, int open, int close, string ans) {
        if (ind < 0) {
            res.push_back(ans);
            return;
        }
        if (open < n) {
            fun(n, ind - 1, open + 1, close, ans + '(');
        }
        if (open > close) {
            fun(n, ind - 1, open, close + 1, ans + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        fun(n, 2 * n - 1, 0, 0, ans);
        return res;
    }
};