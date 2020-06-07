class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;  // stores the element which find greater(m.second = greater) for the find of array num1, we do not need index 
        stack<int> st;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for (int num : nums1) {
            int val = m.count(num) ? m[num] : -1;
            res.push_back(val);
        }
        return res;
    }
};