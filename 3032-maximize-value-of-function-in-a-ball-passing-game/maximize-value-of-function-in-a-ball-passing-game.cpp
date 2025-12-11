class Solution {
public:
    long long getMaxFunctionValue(vector<int>& nums, long long k) {
        int n = nums.size();
        int maxD = 35;

        vector<vector<int>> kth(n, vector<int>(maxD));
        vector<vector<long long>> cost(n, vector<long long>(maxD, 0));

        for (int i = 0; i < maxD; i++) {
            for (int j = 0; j < n; j++) {
                if (!i) {
                    kth[j][i] = nums[j];
                    cost[j][i] = nums[j];
                } else {
                    kth[j][i] = kth[kth[j][i - 1]][i - 1];
                    cost[j][i] = cost[j][i - 1] + cost[kth[j][i - 1]][i - 1];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = i;
            int node = i;
            for (long long j = 0; j < maxD; ++j) {
                if ((1LL << j) & k) {
                    sum += cost[node][j];
                    node = kth[node][j];
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};