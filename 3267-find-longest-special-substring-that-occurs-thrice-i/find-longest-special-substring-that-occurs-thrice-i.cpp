class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                if (s[i] != s[j])
                    break;
                str += s[i];
                mp[str]++;
            }
        }
        int maxi = -1, len = -1;
        for (auto it : mp) {
            string p = it.first;
            int k = p.size();
            if (it.second >= 3 && len < k) {
                maxi = max(maxi, it.second);
                len = k;
            }
        }
        return len;
    }
};