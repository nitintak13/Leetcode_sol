
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long total = 0;
        long long maxDiff = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(1LL * nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        if (total <= k) {
            return 0;
        }

        // Binary search for the minimum achievable maximum difference.
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }

                if (needed > k) {
                    break;
                }
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long x = low;
        long long used = 0;
        long long ans = 0;

        // Reduce every difference to at most x.
        for (long long d : diff) {
            if (d > x) {
                used += d - x;
                ans += x * x;
            } else {
                ans += d * d;
            }
        }

        // Use remaining operations to reduce x to x - 1.
        long long remaining = k - used;

        for (long long d : diff) {
            if (remaining == 0) {
                break;
            }

            if (d >= x && x > 0) {
                ans -= 2 * x - 1;
                --remaining;
            }
        }

        return ans;
    }
};