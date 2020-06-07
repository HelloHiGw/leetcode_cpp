class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> visited(tiles.size(), false);
        int res = 0;
        backtrack(-1, tiles, visited, res);  // be careful of -1, not 0
        return res - 1;  // minus the empty "" prefix
    }
    
    void backtrack(int k, string& s, vector<bool>& visited, int& res) {
        if (k == s.size()) {
            return;
        }
        ++res;
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i] || i && s[i] == s[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            backtrack(k + 1, s, visited, res);
            visited[i] = false;
        }
    }
};