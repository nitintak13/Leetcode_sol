class Solution {
public:
    vector<vector<int>> ans;
    void f(int idx, int t, int k, vector<int>& arr, vector<int>& v) {
        if (v.size() == k && t == 0) {
            ans.push_back(v);
            return;
        }
        if (v.size() > k || t < 0)
            return;
        for (int i = idx; i < arr.size(); i++) {
            if (t >= arr[i]) {
                v.push_back(arr[i]);
                f(i + 1, t - arr[i], k, arr, v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> v;
        f(0, n, k, arr, v);
        return ans;
    }
};