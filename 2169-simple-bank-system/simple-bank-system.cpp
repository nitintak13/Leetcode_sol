class Bank {
private:
    vector<long long> bal;
    int n;

public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        bal.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            bal[i + 1] = balance[i];
        }
    }

    bool transfer(int a1, int a2, long long money) {
        if (a1 < 1 || a2 < 1 || a1 > n || a2 > n)
            return false;
        if (bal[a1] >= money) {
            bal[a1] -= money;
            bal[a2] += money;
            return true;
        }
        return false;
    }

    bool deposit(int a, long long money) {
        if (a < 1 || a > n)
            return false;
        bal[a] += money;
        return true;
    }

    bool withdraw(int a, long long money) {
        if (a < 1 || a > n || bal[a] < money)
            return false;

        bal[a] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */