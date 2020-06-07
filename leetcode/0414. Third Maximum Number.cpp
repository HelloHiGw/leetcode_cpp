// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
//         for (int num : nums) {
//             if (num == first || num == second || num == third) continue;
//             if (num > first) {
//                 third = second;
//                 second = first;
//                 first = num;
//             } else if (num > second) {
//                 third =  second;
//                 second = num;
//             } else if (num > third) {
//                 third = num;
//             }
//         }
//         return third == LLONG_MIN ? first : third;
//     }
// };

// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         unordered_map<int, int> m;
//         for (int num : nums) {
//             if (m[num] == 0) {
//                 pq.push(num);
//                 if (pq.size() > 3) pq.pop();
//                 m[num] = 1;
//             }
//         }
//         if (pq.size() == 2 ) {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (int num : nums) {
            st.insert(num);
            if (st.size() > 3) st.erase(st.begin());
        }
        if (st.size() == 2) st.erase(st.begin());
        return *st.begin();
    }
};

