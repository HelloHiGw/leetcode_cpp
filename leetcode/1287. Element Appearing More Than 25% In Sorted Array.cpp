// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         for (int i = 0, j = 0; i < arr.size(); i = j) {
//             while (j < arr.size() && arr[j] == arr[i]) ++j;
//             if (j - i > 0.25 * arr.size()) return arr[i];
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> v{arr[n / 4], arr[n / 2], arr[n * 3 / 4]};
        for (int val : v) {
            int first = firstOccurrence(arr, val);
            int last = lastOccurrence(arr, val);
            if (last - first + 1 > arr.size() * 0.25) return val;
        }
        return -1;
    }
    
    int firstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    int lastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low - 1;
    }
};