class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> v(n, 0);
        v[n - 1] = nums[n - 1];
        dq.push_back(n - 1);
        int sum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            while (!dq.empty() && dq.front() > i + k) {
                dq.pop_front();
            }
            v[i] = v[dq.front()] + nums[i];

            while (!dq.empty() && v[dq.back()] <= v[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return v[0];
    }
};