// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> st1(nums1.begin(), nums1.end());
//         unordered_set<int> st2(nums2.begin(), nums2.end());
//         vector<int> res;
//         for (int num : st1) {
//             if (st2.count(num)) res.push_back(num);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> intersection;
        for (int num : nums2) {
            if (st.count(num)) intersection.insert(num);
        }
        vector<int> res;
        for (int num : intersection) res.push_back(num);
        return res;
    }
};