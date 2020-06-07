// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         for (int i = 0; i < height.size(); ++i) {
//             int maxLeft = 0, maxRight = 0;
//             for (int j = 0; j <= i; ++j) maxLeft = max(maxLeft, height[j]);
//             for (int j = i; j < height.size(); ++j) maxRight = max(maxRight, height[j]);
//             res += min(maxLeft, maxRight) - height[i];
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         vector<int> maxLeft(height.size()), maxRight(height.size());
//         for (int i = 0; i < height.size(); ++i) {
//             maxLeft[i] = i == 0 ? height[i] : max(maxLeft[i - 1], height[i]);
//         }
//         for (int i = height.size() - 1; i >= 0; --i) {
//             maxRight[i] = i == height.size() - 1 ? height[i] : max(maxRight[i + 1], height[i]);
//         }
//         for (int i = 0; i < height.size(); ++i) {
//             res += min(maxLeft[i], maxRight[i]) - height[i];
//         }
//         return res;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int res = 0;
        int low = 0, high = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (low <= high) {
            maxLeft = max(maxLeft, height[low]);
            maxRight = max(maxRight, height[high]);
            if (maxLeft < maxRight) {
                res += maxLeft - height[low];
                ++low;
            } else {
                res += maxRight - height[high];
                --high;
            }
        }
        return res;
    }
};