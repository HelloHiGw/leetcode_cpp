// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         if (m > n) return findMedianSortedArrays(nums2, nums1);
//         int iMin = 0, iMax = m;
//         while (iMin <= iMax) {
//             int i = (iMin + iMax) / 2;
//             int j = (m + n + 1) / 2 - i;
//             if (i - 1 >= 0 && i - 1 < m && j >= 0 && j < n && nums1[i - 1] > nums2[j]) {
//                 iMax = i - 1;
//             } else if (i >= 0 && i < m && j - 1 >= 0 && j - 1 < n && nums2[j - 1] > nums1[i]) {
//                 iMin = i + 1;
//             } else {
//                 int leftMax = -1;
//                 if (i == 0) {
//                     leftMax = nums2[j - 1];
//                 } else if (j == 0) {
//                     leftMax = nums1[i - 1];
//                 } else {
//                     leftMax = max(nums1[i - 1], nums2[j - 1]);
//                 }
                
//                 if ((m + n) % 2 == 1) return leftMax;
                
//                 int rightMin = -1;
//                 if (i == m) {
//                     rightMin = nums2[j];
//                 } else if (j == n) {
//                     rightMin = nums1[i];
//                 } else {
//                     rightMin = min(nums1[i], nums2[j]);
//                 }
//                 return (leftMax + rightMin) / 2.0;
//             }
//         }
//         return 0;
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int iMin = 0, iMax = m;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i - 1 >= 0 && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            } else {
                int leftMax = i == 0 ? nums2[j - 1] : j == 0 ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]);
                
                if ((m + n) % 2 == 1) return leftMax;
                
                int rightMin = i == m ? nums2[j] : j == n ? nums1[i] : min(nums1[i], nums2[j]);
                return (leftMax + rightMin) / 2.0;
            }
        }
        return 0;
    }
};