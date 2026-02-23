class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        unordered_set<string> st;
        string f = "";

        for (int j = 0; j < n; j++) {
            f += s[j];

            // keep window size = k
            if (f.size() > k) {
                f.erase(0, 1);
            }

            // when window size is exactly k
            if (f.size() == k) {
                st.insert(f);
            }
        }

        return st.size() == (1 << k);
    }
};