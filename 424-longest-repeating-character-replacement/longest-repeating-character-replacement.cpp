class Solution {
public:
    int characterReplacement(string s, int t) {
        int n = s.size();
        vector<int> ch(26, 0);
        int i = 0, j = 0;
        int maxi = 0, len = 0, ans = 0;
        while (j < n) {
            ch[s[j] - 'A']++;
            maxi = max(maxi, ch[s[j] - 'A']);
            while (j - i + 1 - maxi > t) {
                ch[s[i] - 'A']--;
                maxi = 0;
                for (int k = 0; k < 26; k++) {
                    maxi = max(maxi, ch[k]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};