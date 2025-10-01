class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
            if (sum == x) {
                ans = min(ans, i + 1);
            }
        }
        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            int left = x - sum;
            if (mp.find(left) != mp.end() && mp[left] < i) {
                ans = min(ans, n - i + mp[left] + 1);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};