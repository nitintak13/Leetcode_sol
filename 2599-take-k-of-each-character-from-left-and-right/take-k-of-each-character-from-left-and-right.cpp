class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        // if (n < k)
        //     return -1;
        vector<int> v(3, 0);
        for (int i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }
        if (v[0] < k || v[1] < k || v[2] < k)
            return -1;
        int cnt = 0;
        int i = 0, j = 0;
        while (j < n) {
            v[s[j] - 'a']--;
            while (v[0] < k || v[1] < k || v[2] < k) {
                v[s[i] - 'a']++;
                i++;
            }
            cnt = max(cnt, j - i + 1);
            j++;
        }
        return n - cnt;
    }
};