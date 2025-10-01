class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int k = sum - x;
        int i = 0, j = 0;
        int maxi = -1;
        sum = 0;
        while (j < n) {
            sum += nums[j];
            while (i<n && sum > k) {
                sum -= nums[i];
                i++;
            }
            if (sum == k)
                maxi = max(maxi, j - i + 1);
            j++;
        }
        if (maxi == -1)
            return -1;
        return n - maxi;
    }
};