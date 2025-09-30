class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 2) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k + 1] == nums[k]) {
                        k--;
                    }
                }
            }
            i++;
            while (i < n - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return ans;
    }
};