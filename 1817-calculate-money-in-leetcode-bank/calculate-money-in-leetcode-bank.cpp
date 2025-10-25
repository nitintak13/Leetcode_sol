class Solution {
public:
    int totalMoney(int n) {
        int cal = 0, x, y;
        y = n / 7;
        x = n % 7;
        cal = x * y + ((y * (y - 1)) / 2) * 7;
        cal = cal + (x * (x + 1)) / 2 + 28 * y;
        return cal;
    }
};