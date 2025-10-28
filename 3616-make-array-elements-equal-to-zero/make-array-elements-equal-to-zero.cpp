class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, total = 0;
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++) {
            total += nums[i];
            pre[i] = total;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int left = i - 1 >= 0 ? pre[i - 1] : 0;
                int right = total - left;
                if (left == right)
                    ans += 2;
                else if (abs(left - right) == 1)
                    ans += 1;
            }
        }
        return ans;
    }
};