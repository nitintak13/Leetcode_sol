class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int res = 0;
        while (j < n) {
            if (nums[j] <= (nums[i] + 2 * k)) {
                j++;
            } else {
                res = max(res, j - i);
                i++;
            }
        }
        res = max(res, j - i);
        return res;
    }
};