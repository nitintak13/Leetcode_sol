class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> finish(n, 0LL);
        for (int j = 0; j < m; j++) {
            finish[0] += skill[0] * mana[j];
            for (int i = 1; i < n; i++) {
                finish[i] =
                    max(finish[i], finish[i - 1]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; i--) {
                finish[i - 1] = finish[i] - 1LL * mana[j] * skill[i];
            }
        }
        return finish[n - 1];
    }
};