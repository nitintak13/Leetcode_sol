class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int r = ((nums[i] % value) + value) % value;
            mp[r]++;
        }
        int i = 0;
        int ans = 0;
        while (true) {
            if (mp[i % value] > 0) {
                mp[i % value]--;
                ans++;
            } else
                break;
            i++;
        }
        return ans;
    }
};
