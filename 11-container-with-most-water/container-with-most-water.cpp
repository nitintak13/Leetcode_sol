class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxi = 0;

        while (left < right) {
            int water = min(height[left], height[right]) * (right - left);

            maxi = max(water, maxi);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxi;
    }
};