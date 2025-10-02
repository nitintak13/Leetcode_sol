class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;
        unordered_map<int, int> freq;
        long long sum = 0;
        while (j < n) {
            sum += nums[j];
            freq[nums[j]]++;
            if (j - i + 1 > k) {
                sum -= nums[i];
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);

                i++;
            }
            if (freq.size() == k && j - i + 1 == k) {
                ans = max(ans, sum);
            }
            j++;
        }
        return ans;
    }
};