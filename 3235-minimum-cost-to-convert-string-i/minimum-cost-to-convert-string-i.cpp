class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> mat(26, vector<long long>(26, LLONG_MAX));

        int m = original.size();
        for (int i = 0; i < m; i++) {
            mat[original[i] - 'a'][changed[i] - 'a'] =
                min(mat[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        for (int i = 0; i < 26; i++) {
            mat[i][i] = 0;
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX &&
                        mat[i][j] > mat[i][k] + mat[k][j]) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (mat[source[i] - 'a'][target[i] - 'a'] < LLONG_MAX)
                ans += mat[source[i] - 'a'][target[i] - 'a'];
            else
                return -1;
        }
        return ans;
    }
};