class SnapshotArray {
public:
    vector<int> arr;
    int cnt;
    int l;
    unordered_map<int, vector<pair<int, int>>> mp;
    unordered_set<int> changed;
    SnapshotArray(int l) {
        arr.resize(l, 0);
        this->l = l;
        cnt = 0;
    }

    void set(int i, int val) {
        if (i >= 0 && i < l) {
            arr[i] = val;
            changed.insert(i);
        }
    }

    int snap() {
        for (auto it : changed)
            mp[it].push_back({cnt, arr[it]});
        if (!changed.empty())
            changed.clear();

        return cnt++;
    }

    int get(int index, int s) {
        if (index < 0 || index >= l)
            return -1;

        auto& v = mp[index];
        if (v.empty())
            return 0;

        int lo = 0, hi = v.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid].first <= s) {
                ans = v[mid].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */