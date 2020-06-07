class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto &f : flights) {
            graph[f[0]][f[1]] = f[2];
        }
        queue<pair<int, int>> q;
        q.push({0, src});
        int res = INT_MAX;
        ++K;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int price = q.front().first, v = q.front().second;
                q.pop();
                if (v == dst) res = min(res, price);  // the min in k layers
                for (auto &it : graph[v]) {
                    if (price + it.second > res) continue;  // prune or TLE
                    q.push({price + it.second, it.first});
                }
            }
            if (K-- == 0) break;  // will not exceed k layers
        }
        return res == INT_MAX ? -1 : res;
    }
};

/*
we needed visited map so that it wont go into infinite loop. here "k" limited the 
time we can visit a single node that it wont go into an infinite loop.
*/


// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         unordered_map<int, unordered_map<int, int>> graph;
//         for (auto &f : flights) {
//             graph[f[0]][f[1]] = f[2];
//         }
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//         pq.push({0, src, K + 1});
//         while (!pq.empty()) {
//             vector<int> v = pq.top();
//             pq.pop();
//             int price = v[0], city = v[1], steps = v[2];
//             if (city == dst) return price;
//             if (steps) {
//                 for (auto &it : graph[city]) {
//                     pq.push({price + it.second, it.first, steps - 1});
//                 }
//             }
//         }
//         return -1;
//     }
// };

/*
It's basically BFS with a priority queue instead of a normal one rather than 
Dijkstra without costs array. it is hard to understand than the first bfs

it will tackle with small distance vertex, if can not get the answer in k + 1 steps
then tackle with bigger distance vertex
*/