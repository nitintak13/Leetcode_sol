class Solution {
public:
    void fun(int ind, int k, vector<int>& arr, int sum, vector<int> comb,
             vector<vector<int>>& ans) {
        int n = arr.size();

        if (sum == k) {
            ans.push_back(comb);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (i > ind && arr[i] == arr[i - 1]) {
                continue; // Skip duplicates
            }
            if (sum + arr[i] > k)
                break; // Prune the search

            vector<int> newComb = comb; // Create a new copy explicitly
            newComb.push_back(arr[i]);  // Add the current element
            fun(i + 1, k, arr, sum + arr[i], newComb,
                ans); // Recurse with new copy
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        vector<vector<int>> ans;
        int n = arr.size();
        vector<int> comb;
        sort(arr.begin(), arr.end());
        fun(0, k, arr, 0, comb, ans);
        return ans;
    }
};