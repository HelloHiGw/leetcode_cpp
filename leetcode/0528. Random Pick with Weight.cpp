/*
Use accumulated freq array to get idx.
w[] = {2,5,3,4} => wsum[] = {2,7,10,14}
then get random val [0, 14)

idx in [0,1] return 0
idx in [2,6] return 1
idx in [7,9] return 2
idx in [10,13] return 3

that is upperBound
*/
class Solution {
public:
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); ++i) {
            w[i] += w[i - 1];
        }
        sum = w;
    }
    
    int pickIndex() {
        int n = sum.back();
        // pass, RAND_MAX = INT_MAX in leetcode, usually it is 32767
        // int rnd = rand() % n;
        // pass
        int rnd = rand() / (1.0 * RAND_MAX + 1) * n;
        
        // 56 / 57 test cases passed. algorithm generate [min, max]
        // cannot apply to generate [0, N)
        // int rnd = round(1.0 * rand() / RAND_MAX * (n - 1));
        
        // [min, max] can apply to generate [0, N)
        // thought it is different from normal generate [0, N), it can pass oj
        //int rnd = rand() / (1.0 * RAND_MAX / n + 1);
        return upperBound(rnd);
    }
    
private:
    vector<int> sum;
    
    int upperBound(int target) {
        int left = 0, right = sum.size(), mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (sum[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */