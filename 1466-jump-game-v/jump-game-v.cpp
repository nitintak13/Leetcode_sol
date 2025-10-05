class Solution {
public:
    int n, D;
    vector<int> a;
    vector<int> memo;
    int dfs(int i) {
        if (memo[i] != -1)
            return memo[i];
        int best = 1;
        for (int j = i + 1; j <= min(n - 1, i + D); ++j) {
            if (a[j] >= a[i])
                break;
            best = max(best, 1 + dfs(j));
        }
        for (int j = i - 1; j >= max(0, i - D); --j) {
            if (a[j] >= a[i])
                break;
            best = max(best, 1 + dfs(j));
        }
        memo[i] = best;
        return best;
    }

    int maxJumps(vector<int>& arr, int d) {
        a = arr;
        n = a.size();
        D = d;
        memo.assign(n, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
