class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int maxi = -1;
            char col = colors[i];
            while (i < n && colors[i] == col) {
                ans += time[i];
                maxi = max(maxi, time[i]);
                i++;
            }

            if (maxi != -1)
                ans -= maxi;
            if (i < n)
                i--;
        }
        return ans;
    }
};