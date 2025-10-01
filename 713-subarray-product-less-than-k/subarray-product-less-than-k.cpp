class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long prod = 1;
        int i = 0, j = 0;
        int cnt = 0;
        if (k <= 1)
            return 0;
        while (j < n) {
            prod *= nums[j];
            while (prod >= k) {
                prod = prod / nums[i];
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }
};