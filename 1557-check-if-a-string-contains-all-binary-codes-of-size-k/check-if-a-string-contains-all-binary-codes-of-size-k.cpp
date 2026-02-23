class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<string, int> mp;
        string f = "";
        while (j < n) {
            f += s[j];

            if (j - i >= k) {
                f.erase(0, 1);
                i++;
            }
            if (f.size() == k) {
                mp[f]++;
            }
            j++;
        }
        return pow(2, k) == mp.size();
    }
};