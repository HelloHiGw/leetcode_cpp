class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> hasOut;
        for (auto& path : paths) {
            if (!hasOut.count(path[1])) {
                hasOut[path[1]] = false;
            }
            hasOut[path[0]] = true;
        }
        
        for (auto& it : hasOut) {
            if (it.second == false) return it.first;
        }
        return "";
    }
};