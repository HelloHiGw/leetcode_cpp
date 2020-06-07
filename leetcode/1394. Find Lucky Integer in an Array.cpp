class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num : arr) {
            ++m[num];
        }
        int res = -1;
        for (auto &it : m) {
            if (it.first == it.second) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};