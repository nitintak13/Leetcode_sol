class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1e8;
        int i = 0, j = 0;
        long long sum = 0;
        deque<int> dq;
        vector<long long> v(n, 0);
        while (j < n) {
            sum += nums[j];
            v[j] = sum;
            if (v[j] >= k) {
                ans = min(ans, j + 1);
            }
            while (!dq.empty() && v[dq.back()] >= v[j]) {
                dq.pop_back();
            }

            while (!dq.empty() && v[j] - v[dq.front()] >= k) {
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            dq.push_back(j);
            j++;
        }
        return ans == 1e8 ? -1 : ans;
    }
};