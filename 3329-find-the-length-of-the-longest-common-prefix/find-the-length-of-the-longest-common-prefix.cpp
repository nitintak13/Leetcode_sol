class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<string> st;
        for (int i = 0; i < m; i++) {
            string str = to_string(arr2[i]);
            for (int j = 0; j < str.size(); j++) {
                st.insert(str.substr(0, j + 1));
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            string str = to_string(arr1[i]);
            for (int j = 0; j < str.size(); j++) {
                if (st.find(str.substr(0, j + 1)) != st.end()) {
                    mx = max(mx, j + 1);
                }
            }
        }
        return mx;
    }
};