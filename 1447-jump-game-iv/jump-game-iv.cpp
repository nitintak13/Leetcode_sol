class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        queue<int> q;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        q.push(0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while (!q.empty()) {
            int ind = q.front();
            q.pop();

            if (ind + 1 < n && dist[ind + 1] > dist[ind] + 1) {
                dist[ind + 1] = dist[ind] + 1;
                q.push(ind + 1);
            }
            if (ind - 1 >= 0 && dist[ind - 1] > dist[ind] + 1) {
                dist[ind - 1] = dist[ind] + 1;
                q.push(ind - 1);
            }
            for (auto it : mp[arr[ind]]) {
                if (dist[it] > dist[ind] + 1) {
                    q.push(it);
                    dist[it] = dist[ind] + 1;
                }
            }
            mp[arr[ind]].clear();
        }
        return dist[n - 1];
    }
};