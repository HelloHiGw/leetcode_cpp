class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (k == 0 && m[num] == 1) {
                ++res;
            }
            else if (m[num] == 0) {
                if (m[num - k]) ++res;
                if (m[num + k]) ++res;
            }
            m[num] += 1;
        }
        return res;
    }
};
