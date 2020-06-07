class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 1;
        vector<string> res;
        for (int i = 0; i < target.size(); ++i) {
            while (j < target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                ++j;
            }
            res.push_back("Push");
            ++j;
        }
        
        return res;
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (int i = 1, j = 0; i <= n && j < target.size(); ++i) {
            res.push_back("Push");
            if (i == target[j]) {
                ++j;
            } else {
                res.push_back("Pop");
            }
        }
        
        return res;
    }
};