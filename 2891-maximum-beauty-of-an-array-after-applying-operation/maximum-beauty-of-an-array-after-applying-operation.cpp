class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i] - k, nums[i] + k});
        }
        sort(v.begin(), v.end());
        deque<int> dq;
        int res = 0;
        for (auto it : v) {
            while (!dq.empty() && dq.front() < it.first) {
                dq.pop_front();
            }

            dq.push_back(it.second);
            int p = dq.size();
            res = max(res, p);
        }
        return res;
    }
};