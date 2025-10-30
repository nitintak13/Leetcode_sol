class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if (n == 0)
            return 0;
        int prev = target[0];
        int ans = target[0];
        for (int i = 1; i < n; i++) {
            int curr = target[i];
            if (curr > prev)
                ans += (curr - prev);
            prev = curr;
        }
        return ans;
    }
};