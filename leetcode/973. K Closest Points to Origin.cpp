// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
//         for (vector<int>& v : points) {
//             pq.push(v);
//             if (pq.size() > K) pq.pop();
//         }
//         vector<vector<int>> res;
//         while (!pq.empty()) {
//             res.push_back(pq.top());
//             pq.pop();
//         }
//         return res;
//     }

// private:
//     struct cmp{
//         bool operator() (vector<int> v1, vector<int> v2) {
//             return v1[0] * v1[0] + v1[1] * v1[1] - v2[0] * v2[0] - v2[1] * v2[1] < 0;
//         }
//     };
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int start = 0, end = points.size() - 1;
        while (true) {
            int pos = partition(points, start, end);
            if (pos + 1 == K) {
                return vector<vector<int>>(points.begin(), points.begin() + K);
            } else if (pos + 1 < K) {
                start = pos + 1;
            } else {
                end = pos - 1;
            }
        }
        return {};
    }
    
private:   
    int partition(vector<vector<int>>& points, int start, int end) {
        auto temp = points[start];
        while (start < end) {
            while (start < end && compare(points[end], temp) > 0) --end;
            points[start] = points[end];
            while (start < end && compare(points[start], temp) <= 0) ++start;
            points[end] = points[start];
        }
        points[start] = temp;
        return start;
    }
    
    int compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] * v1[0] + v1[1] * v1[1] - v2[0] * v2[0] - v2[1] * v2[1];
    }
};