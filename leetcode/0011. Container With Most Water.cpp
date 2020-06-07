class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        while (i < j) {
            res = max(res, (j - i) * min(height[i], height[j]));
            height[i] > height[j] ? --j : ++i;
        }
        return res;
    }
};

/*
https://leetcode.com/problems/container-with-most-water/discuss/200246/Proof-by-formula
One thing that is ignored in the explanation is the h[i] == h[j] case.
You need to prove that in this case, it does not matter whether you perform i++ or j--, because if h[i] == h[j], neither (i+1, j) or (i, j-1) can be potential solutions because the area obtained is necessarily smaller than (i, j).
*/