class Solution {
public:
    vector<string> ans;

    void fun(int ind, string digits, string& res,
             unordered_map<char, string> key) {
        int n = digits.size();
        if (ind >= n) {
            ans.push_back(res);
            return;
        }
        string s = key[digits[ind]];
        for (int i = 0; i < s.size(); i++) {
            res += s[i];
            fun(ind + 1, digits, res, key);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> key = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        if (digits.size() == 0)
            return ans;
        string res;
        fun(0, digits, res, key);
        return ans;
    }
};