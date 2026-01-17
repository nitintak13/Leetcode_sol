class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& left,
                                vector<vector<int>>& right) {
        long long area = 0;
        for (int i = 0; i < left.size(); i++) {
            for (int j = i + 1; j < left.size(); j++) {
                long long minimum_x = max(left[i][0], left[j][0]);
                long long maximum_x = min(right[i][0], right[j][0]);
                long long minimum_y = max(left[i][1], left[j][1]);
                long long maximum_y = min(right[i][1], right[j][1]);

                if (minimum_x < maximum_x && minimum_y < maximum_y) {
                long long s = min(maximum_x - minimum_x, maximum_y - minimum_y);
                area = max(area, s * s);
                }
            }
        }
        return area;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();