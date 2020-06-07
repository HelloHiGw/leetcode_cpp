// O(n * (L + n)) ?
// class Solution {
// public:
//     int numSpecialEquivGroups(vector<string>& A) {
//         vector<vector<unordered_multiset<char>>> group;
//         for (string s : A) {
//             unordered_multiset<char> even, odd;
//             for (int i = 0; i < s.size(); ++i) {
//                 if (i % 2 == 0) {
//                     even.insert(s[i]);
//                 } else {
//                     odd.insert(s[i]);
//                 }
//             }
//             vector<unordered_multiset<char>> curr = {even, odd};
//             bool find = false;
//             for (auto &v : group) {  // can't use unordered_set to accelerate finding, problem with vector<unordered_multiset<char>> as key 
//                 if (v == curr) {
//                     find = true;
//                     break;
//                 }
//             }
//             if (!find) group.push_back(curr);
//         }
//         return group.size();
//     }
// };

// O(n * LlogL)
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for (string &s : A) {
            string even, odd;
            for (int i = 0; i < s.size(); ++i) {
                if (i % 2 == 0) {
                    even += s[i];
                } else {
                    odd += s[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};