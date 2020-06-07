// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {
//         vector<int> v(heights);
//         sort(v.begin(), v.end());
//         int res = 0;
//         for (int i = 0; i < v.size(); ++i) {
//             if (v[i] != heights[i]) ++res;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101);
        for (int num : heights) {
            freq[num] += 1;
        }
        int currNum = 0, res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (freq[currNum] == 0) ++currNum;
            if (currNum != heights[i]) ++res;
            --freq[currNum];
        }
        return res;
    }
};