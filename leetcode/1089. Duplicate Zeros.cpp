// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         int count = 0, i = 0;
//         for (i = 0; i < arr.size(); ++i) {
//             if (arr[i] == 0) ++count;
//             if (i + count >= arr.size() - 1) break;
//         }
//         if (count == 0) return;
//         int index = arr.size() - 1, j = i;
//         if (i + count > arr.size() - 1) {
//             arr[index--] = arr[j--];
//         }
//         while (j >= 0) {
//             if (arr[j] == 0) arr[index--] = arr[j];
//             arr[index--] = arr[j--];           
//         }
//     }
// };

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) ++count;
        }
        if (count == 0) return;
        int size = arr.size() + count;
        for (int i = arr.size() - 1, j = size - 1; i >= 0; --i, --j) {
            if (arr[i] != 0) {
                if (j < arr.size()) arr[j] = arr[i];
            } else {
                if (j < arr.size()) arr[j] = 0;
                --j;
                if (j < arr.size()) arr[j] = 0;
            }
        }
    }
};