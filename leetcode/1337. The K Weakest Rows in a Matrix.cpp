class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = count(mat[i]);
            //while (cnt < mat[i].size() && mat[i][cnt] == 1) ++cnt;
            v.push_back({cnt, i});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = v[i].second;
        }
        return res;
    }
    
    bool static cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    
    int count(vector<int>& v) {
        int low = 0, high = v.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (v[mid] != 0) {  // the firstoccurrence of 0
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};