// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         int res = 0;
//         for (int a : arr1) {
//             bool flag = true;
//             for (int b : arr2) {
//                 if (abs(a - b) <=d ) {
//                     flag = false;
//                     break;
//                 }
//             }
//             res += flag;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());
        for (int num : arr1) {
            if (lowerBound(arr2, num - d) == upperBound(arr2, num + d)) ++res;
            // if (lower_bound(arr2.begin(), arr2.end(), num - d) == upper_bound(arr2.begin(), arr2.end(), num + d)) ++res;
        }
        return res;
    }

    
    int lowerBound(vector<int>&arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    int upperBound(vector<int>&arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};