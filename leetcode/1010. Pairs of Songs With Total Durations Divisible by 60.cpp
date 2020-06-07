class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int res = 0;
        for (int num : time) {
            num %= 60;
            res += m[(60 - num) % 60];
            m[num] += 1;
        }
        return res;
    }
};