/*
Input: ["a==b","b==c","a==c"]
Output: true

Input: ["a==b","b!=c","c==a"]
Output: false
*/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        initialize();
        for (string &s : equations) {
            if (s[1] == '=') {
                int x = s[0] - 'a', y = s.back() - 'a';
                union_(x, y);
            }
        }
        for (string &s : equations) {
            if (s[1] == '!') {
                int x = s[0] - 'a', y = s.back() - 'a';
                if (findFather(x) == findFather(y)) return false;
            }
        }
        return true;
    }

private:
    // if father[x] == x, x is root of a set
    vector<int> father;

    void initialize() {
        for (int i = 0; i < 26; ++i) {  // initialize every node as root
            father.push_back(i);
        }
    }
    
    int findFather(int x) {
        int t = x;
        while (x != father[x]) x = father[x];
        while (t != x) {  // press the path, set father[pathNode] = root, expecting findFather in O(1)
            int f = father[t];
            father[t] = x;
            t = f;
        }
        return x;
    }
    
    // father[1] = father[2] = father[0] = 0, father[3] = 3
    // after union_(0, 3), father[0] = 3, but father[1] is still 0
    // so use findFather(1) = 3 not father[1] = 0 when you need father of some node
    void union_(int x, int y) {  // union is key word in cpp
        int fx = findFather(x), fy = findFather(y);
        if (fx != fy) father[fx] = fy;
    }
};