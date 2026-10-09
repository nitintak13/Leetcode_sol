
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Need a pair of consecutive ')'.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert the missing ')'.
                    ans++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert '(' to match this closing pair.
                    ans++;
                }
            }
        }

        // Each unmatched '(' requires two ')'.
        ans += 2 * open;

        return ans;
    }
};
