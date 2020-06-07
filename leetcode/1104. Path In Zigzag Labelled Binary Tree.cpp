class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 1;
        while (pow(2, level) <= label) ++level;
        vector<int> res(level);
        while (level > 0) {
            res[level - 1] = label;
            // min + max = x + y as four dots in a axis
            // run the inversion formula at every level because at every level the row is inverted relative to the previous row
            label = pow(2, level) - 1 + pow(2, level - 1) - label;
            label /= 2;
            --level;
        }
        return res;
    }
};