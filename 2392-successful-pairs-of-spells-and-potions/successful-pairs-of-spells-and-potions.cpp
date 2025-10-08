class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& nums,
                                long long k) {
        int n = spells.size();
        int m = nums.size();
        vector<int> ans(n, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = 0, h = m - 1;
            while (l <= h) {
                int mid = (l + h) / 2;
                if ((long long)nums[mid] * spells[i] >= k) {
                    ans[i] = m - mid;
                    h = mid - 1;
                } else
                    l = mid + 1;
            }
        }
        return ans;
    }
};