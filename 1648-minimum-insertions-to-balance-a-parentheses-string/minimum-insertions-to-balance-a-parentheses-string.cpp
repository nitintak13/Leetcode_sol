class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int i = s.size() - 1, ans = 0;
        while (i >= 0) {
            if (s[i] == ')') {
                st.push(i);
            } else {
                if (st.empty()) {
                    ans += 2;
                    i--;
                    continue;
                }
                int sf = st.top();
                st.pop();
                if (st.empty()) {
                    ans += 1;
                    i--;
                    continue;
                }
                int sf2 = st.top();
                st.pop();
                if (abs(sf2 - sf) != 1) {
                    ans++;
                    st.push(sf2);
                }
            }
            i--;
        }
        while (!st.empty()) {
            int it = st.top();
            st.pop();
            if (!st.empty() && abs(it - st.top()) == 1) {
                st.pop();
                ans++;
            } else {
                ans += 2;
            }
        }
        return ans;
    }
};