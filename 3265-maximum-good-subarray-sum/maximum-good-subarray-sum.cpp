class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] += prefix[i] + nums[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i] - k) != mp.end()) {
                ans = max(ans, prefix[i + 1] - prefix[mp[nums[i] - k]]);
            }
            if (mp.find(nums[i] + k) != mp.end()) {
                ans = max(ans, prefix[i + 1] - prefix[mp[nums[i] + k]]);
            }
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                if (prefix[i] - prefix[mp[nums[i]]] < 0) {
                    mp[nums[i]] = i;
                }
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};