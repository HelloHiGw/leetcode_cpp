class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xors(n + 1);
        for (int i = 0; i < n; ++i) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        
        vector<int> res;
        for (auto& q : queries) {
            res.push_back(xors[q[1] + 1] ^ xors[q[0]]);
        }
        
        return res;
    }
};