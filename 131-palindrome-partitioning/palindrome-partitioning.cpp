class Solution {
public:
    vector<vector<string>> ans;
    bool check(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void fun(int ind, int n, string s, vector<string> res) {
        if (ind >= n) {
            ans.push_back(res);
            return;
        }
        for (int i = ind; i < n; i++) {

            if (check(s, ind, i)) {
                string p = s.substr(ind, i - ind + 1);
                res.push_back(p);
                fun(i + 1, n, s, res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> res;
        fun(0, n, s, res);
        return ans;
    }
};