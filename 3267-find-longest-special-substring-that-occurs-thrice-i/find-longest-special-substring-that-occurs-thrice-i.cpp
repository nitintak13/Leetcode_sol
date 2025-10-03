class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> mat(26, vector<int>(n + 1, 0));
        int l = 0, i = 0, prev = s[0];
        int ans = -1;
        while (i < n) {
            int curr = s[i];
            if (curr == prev) {
                l++;
                mat[s[i] - 'a'][l]++;
            } else {
                l = 1;
                mat[s[i] - 'a'][l]++;
                prev = curr;
            }
            i++;
        }
        for (int row = 0; row < 26; row++) {
            int sum = 0;
            for (int col = n; col >= 1; col--) {
                sum += mat[row][col];
                if (sum >= 3) {
                    ans = max(ans, col);
                    break;
                }
            }
        }
        return ans;
    }
};