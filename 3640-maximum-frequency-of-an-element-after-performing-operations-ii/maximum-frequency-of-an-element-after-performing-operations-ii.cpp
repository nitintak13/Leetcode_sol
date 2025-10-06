class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int n = nums.size();
        map<int, int> range;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            range[nums[i] - k]++;
            range[nums[i] + k + 1]--;
            range[nums[i]] += 0;
            freq[nums[i]]++;
        }
        int ans = 1;
        int prev = 0;
        for (auto it : range) {
            it.second += prev;
            prev = it.second;
            int curr = min(op, it.second - freq[it.first]);
            curr += freq[it.first];
            ans = max(ans, curr);
        }
        return ans;
    }
};