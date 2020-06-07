// find the longest shortest distacne to source vertex s
// if not a connected block, return -1
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> graph;  // similar to adjacency list
        for (auto &t : times) {
            graph[t[0]][t[1]] = t[2];
        }

        vector<int> d = dijkstra(K, N, graph);

        int res = 0;
        for (int i = 1; i <= N; ++i) {
            res = max(res, d[i]);
        }
        return res == INF ? -1: res;
    }

private:
    const int INF = 0x3fffffff;

    /*
    dijkstra
    set : time complexity  O(VlogV + ElogV)      space complexity O(V)
    priority_queue : time complexity  O(VlogV + ElogV)      space complexity O(V + E)
    there is insert(push) in updating d, so adding ElogV
    algorithm note is O(V^2 + E) and O(V) for visited 
    */

    // algorithm note's method, not as good as following, no use
    vector<int> dijkstra1(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<int> d(n + 1, INF);
        d[s] = 0;
        vector<bool> visited(n + 1, false);
         
        for (int i = 0; i < n; ++i) {  // loop n times
            int u = -1, minDist = INF;  // INF, if you set INT_MAX, INF < INT_MAX, unreachable vertex becomes reachable
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && d[j] < minDist) {  // do not forget not visited vertex
                    u = j;
                    minDist = d[j];
                }
            }
            
            if (u == -1) break;  // not a connected block
            visited[u] = true;
            for (auto &it : graph[u]) {
                int v = it.first, dist = it.second;
                if (!visited[v] && d[u] + dist < d[v]) d[v] = d[u] + dist;
            }
        }

        return d; 
    }


    vector<int> dijkstra2(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<int> d(n + 1, INF);
        d[s] = 0;
        vector<bool> visited(n + 1, false);
        set<pair<int, int>> st;
        st.insert({0, s});  // sort by dist and konw the vertex number meanwhile
         
        while (!st.empty()) {
            int u = (*st.begin()).second;  // sort by dist, but we need the corresponding vertex number
            st.erase(*st.begin());
            visited[u] = true;

            for (auto &it : graph[u]) {
                int v = it.first, dist = it.second;
                if (!visited[v] && d[u] + dist < d[v]) {  // d[u] will not be INT_MAX, no overflow
                    st.erase({d[v], v});  // st may not contain {d[v], v}, but does not matter, equals not erase
                    st.insert({d[u] + dist, v});
                    d[v] = d[u] + dist;
                }
            }
        }
        
        return d;
    }
    
    
    /*
    almost the same as set, except that we can not erase {oldDist, v} in pq

    There could be one node with different distances in the pq, 
    but pq will always give you the shortest distance one. 
    And "if(visited[curNode]) continue;" will prevent res to be further 
    updated to a longer distance once we already got a shorter distance for this curNode!
    */
    vector<int> dijkstra3(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<int> d(n + 1, INF);
        d[s] = 0;
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s}); 
         
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visited[u]) continue;  // different
            visited[u] = true;

            for (auto &it : graph[u]) {
                int v = it.first, dist = it.second;
                if (!visited[v] && d[u] + dist < d[v]) {
                    pq.push({d[u] + dist, v});  // different, no erase
                    d[v] = d[u] + dist;
                }
            }
        }
        
        return d;
    }


    // time complexity O(VE)  space complexity O(V)
    vector<int> bellman(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<int> d(n + 1, INF);
        d[s] = 0;
        
        // loop n-1 times, the shortest path tree is at most height of n
        // every loop updates d of a level topdown
        for (int i = 0; i < n - 1; ++i) {  
            bool stop = true;  // prune if height < n
            for (int u = 1; u <= n; ++u) {
                for (auto &it : graph[u]) {
                    int v = it.first, dist = it.second;
                    if (d[u] + dist < d[v]) { // d[u] may be INF, do not use INT_MAX, overflow
                        d[v] = d[u] + dist;  
                        stop = false;
                    }
                }
            }
            if (stop) break;
        }
        
        return d;
    }

    /* 
    Shortest Path Faster Algorithm, the improved version of bellman
    it is similar to dijkstra except that there is set/priority_queue in dijkstra, but queue in SPFA
    dijkstra selects an unvisited vertex with the smallest distance to src every time and will never visit it again

    SPFA is the improved version of bellman
    bellman tackles with all edges every loop
    notice that only when d[u] changes, d[v] can be changed (there is an edge u->v)
    so we can use a queue to store vertexes with changed d, and the vertex may be in queue next time

    time complexity O(E), space complexity O(V)
    */
    vector<int> SPFA(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<int> d(n + 1, INF);
        d[s] = 0;

        vector<bool> inq(n + 1, false);  // inQueue
        queue<int> q;
        q.push(s);
        inq[s] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            // vertex can be pushed into queue many times
            // next time, once d[u] is updated, the neighbors of u may also be updated
            // should set inq[u] = false here to let it in queue next time
            inq[u] = false;  

            for (auto &it : graph[u]) {
                int v = it.first, dist = it.second;
                if (d[u] + dist < d[v]) {
                    d[v] = d[u] + dist;
                    if (!inq[v]) {  // v may be already in the queue
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        
        return d;
    }


    // floyd : shortest path for all vertex
    // time complexity O(V^3)   space complexity O(V^2)
    vector<int> floyd(int s, int n, unordered_map<int, unordered_map<int, int>> &graph) {
        vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
        for (auto &m1 : graph) {  // initialize d with graph
            for (auto &m2 : m1.second) {
                d[m1.first][m2.first] = m2.second;
            }
        }
        for (int i = 1; i <= n; ++i) d[i][i] = 0;  // d[i][i] = 0
        
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
        
        return d[s];
    }

};

