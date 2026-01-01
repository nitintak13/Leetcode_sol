class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans = digits;
        if (digits[n - 1] != 9) {
            ans[n - 1] = digits[n - 1] + 1;
            return ans;
        }
        int i = n - 1;
        while (i >= 0 && digits[i] == 9) {
            ans[i] = 0;
            i--;
        }
        if (i >= 0) {
            ans[i] = digits[i] + 1;
        } else {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};