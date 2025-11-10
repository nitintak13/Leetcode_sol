class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (!st.empty() && st.top() > x)
                st.pop();

            if (x == 0) {
                continue;
            }
            if (st.empty() || st.top() < x) {
                st.push(x);
                ++ans;
            }
        }
        return ans;
    }
};
