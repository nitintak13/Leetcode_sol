class Solution {
public:
    long long fun(int ind, const vector<int>& vals,
                  const unordered_map<int, int>& mp, vector<long long>& memo) {
        int n = vals.size();
        if (ind >= n)
            return 0;
        if (memo[ind] != -1)
            return memo[ind];

        long long res = fun(ind + 1, vals, mp, memo);

        long long take = 1LL * mp.at(vals[ind]) * vals[ind];
        if (ind + 1 < n && vals[ind + 1] == vals[ind] + 1)
            take += fun(ind + 2, vals, mp, memo);
        else
            take += fun(ind + 1, vals, mp, memo);

        res = max(res, take);
        memo[ind] = res;
        return res;
    }

    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> mp;
        vector<int> v;
        for (int x : nums) {
            mp[x]++;
            if (mp[x] == 1)
                v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<long long> memo(v.size(), -1);
        long long ans = fun(0, v, mp, memo);
        return (int)ans;
    }
};
