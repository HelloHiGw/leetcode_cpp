// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//       int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
//       for (int num : nums) {
//         if (num > max3) {
//           max1 = max2;
//           max2 = max3;
//           max3 = num;
//         } else if (num > max2) {
//           max1 = max2;
//           max2 = num;
//         } else if (num > max1) {
//           max1 = num;
//         }
        
//         if (num < min1) {
//           min2 = min1;
//           min1 = num;
//         } else if (num < min2) {
//           min2 = num;
//         }
//       }
//       return max(min1 * min2 * max3, max1 * max2 * max3);
//     }
// };

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, less<int>> nq;
        for (int num : nums) {
            pq.push(num);
            nq.push(num);
            if (pq.size() > 3) pq.pop();
            if (nq.size() > 2) nq.pop();
        }
        int res1 = 1, res2 = 1;
        while (! pq.empty()) {
            if (pq.size() == 1) res2 *= pq.top();
            res1 *= pq.top();
            pq.pop();
        }
        while (! nq.empty()) {
            res2 *= nq.top();
            nq.pop();
        }
        return max(res1, res2);
    }
};