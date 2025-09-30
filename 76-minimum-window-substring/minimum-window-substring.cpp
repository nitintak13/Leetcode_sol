class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        int i = 0, j = 0;
        int ans = 1e9;
        string res;
        int cnt = 0;
        int ind = -1;
        while (j < n) {
            if (mp[s[j]] > 0)
                cnt++;
            mp[s[j]]--;
            while (cnt == m) {
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    ind = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    cnt--;
                i++;
            }

            j++;
        }
        return ind == -1 ? "" : s.substr(ind, ans);
    }
};