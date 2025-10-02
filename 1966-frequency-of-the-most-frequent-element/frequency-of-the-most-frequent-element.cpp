class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 1;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        long long sum = 0;
        while (j < n) {
            sum += nums[j];
            if ((long long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                ++i;
            }

            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};