class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;
        for (int num : arr1) {
            ++count[num];
        }
        vector<int> res(arr1.size());
        int index = 0;
        for (int num : arr2) {
            while (count[num] > 0) {
                res[index++] = num;
                --count[num];
            }
        }
        int rIndex = res.size() - 1;
        for (int i = 1000; i >= 0; --i) {
            while (count[i] > 0) {
                res[rIndex--] = i;
                --count[i];
            }
            if (rIndex == index - 1) break;
        }
        return res;
    }
};