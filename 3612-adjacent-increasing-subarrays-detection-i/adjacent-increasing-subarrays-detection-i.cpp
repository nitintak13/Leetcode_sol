class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 1);
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
                pre[i] = cnt;
            } else {
                cnt = 1;
            }
        }
        for (int i = k; i < n; i++) {
            if (pre[i] >= k && pre[i - k] >= k) {
                return true;
            }
        }
        return false;
    }
};