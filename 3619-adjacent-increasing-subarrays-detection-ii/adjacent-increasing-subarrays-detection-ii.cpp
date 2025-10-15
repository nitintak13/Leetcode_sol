class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int prev = 0, cur = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {

                prev = cur;
                cur = 1;
            }
            k = max(k, min(prev, cur));
            k = max(k, cur / 2);
        }
        return k;
    }
};