class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans) {
        // base case mai solve karta hu
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            // recursive call  karta hu
            solve(nums, i + 1, ans);
            // backtracking
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums, i, ans);
        return ans;
    }
};