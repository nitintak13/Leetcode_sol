class Solution {
public:
    int numWaterBottles(int num, int ex) {
        int cnt = num;
        int full = num;
        int val = 0, carry = 0;
        while (full >= ex) {
            val = full / ex;
            carry = full % ex;
            cnt += val;
            full = val + carry;
        }
        return cnt;
    }
};