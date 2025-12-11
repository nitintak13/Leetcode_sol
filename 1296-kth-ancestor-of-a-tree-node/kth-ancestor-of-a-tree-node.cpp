class TreeAncestor {
    vector<vector<int>> kth;
    int maxi = 0;

public:
    TreeAncestor(int n, vector<int>& parent) {
        int i = 0;
        while (1 << maxi <= n) {
            maxi++;
        }
        kth.resize(n, vector<int>(maxi, -1));
        for (int i = 0; i < maxi; i++) {
            for (int j = 0; j < n; j++) {
                if (!i) {
                    kth[j][i]=parent[j];
                } else if (kth[j][i - 1] != -1) {
                    kth[j][i] = kth[kth[j][i - 1]][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < maxi; i++) {
            if ((1 << i) & k) {
                node = kth[node][i];
                if (node == -1)
                    break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */