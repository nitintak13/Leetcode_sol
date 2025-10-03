class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long> pre(n + 1, 0LL);
        pre[0] = nums[0];

        unordered_map<long long, long long> mp;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        mp[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            int num1 = nums[i] + k;
            int num2 = nums[i] - k;
            if (mp.find(num1) != mp.end()) {
                ans = max(ans, pre[i] - mp[num1]);
            }
            if (mp.find(num2) != mp.end()) {
                ans = max(ans, pre[i] - mp[num2]);
            }
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = pre[i - 1];
            } else {
                mp[nums[i]] = min(mp[nums[i]], pre[i - 1]);
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};