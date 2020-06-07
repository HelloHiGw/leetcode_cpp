// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         set<int> st;
//         unordered_map<int, vector<int>> numToIndex;
//         for (int i = 0; i < arr.size(); ++i) {
//             st.insert(arr[i]);
//             numToIndex[arr[i]].push_back(i);
//         }
//         vector<int> res(arr.size());
//         int r = 1;
//         for (auto it = st.begin(); it != st.end(); ++it) {
//             for (int i : numToIndex[*it]) {
//                 res[i] = r;
//             }
//             ++r;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr);
        sort(v.begin(), v.end());
        unordered_map<int, int> rank;
        for (int num : v) {
            if (rank.find(num) == rank.end()) {
                rank[num] = rank.size() + 1;
            }
        }
        vector<int> res(arr);
        for (int i = 0; i < arr.size(); ++i) {
            res[i] = rank[arr[i]];
        }
        return res;
    }
};