class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);  // initialize res with -1, so do not need set st.element to -1(not fuound) at the end
        for (int i = 0; i < 2 * n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {  // here is nums, not res, 1019 is linkedlist, so we need res to store the val
                res[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) st.push(i);  // we do not need i >= n in res
        }
        return res;
    }
};
