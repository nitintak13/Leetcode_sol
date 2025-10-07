class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        map<int, int> mp;
        int n = trips.size();
        for (auto it : trips) {
            mp[it[1]] += it[0];
            mp[it[2]] -= it[0];
        }
        int cnt = 0;
        for (auto it : mp) {
            cnt += it.second;
            if (cnt > cap)
                return false;
        }
        return true;
    }
};