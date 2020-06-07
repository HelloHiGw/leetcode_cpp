class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        int i = 0;
        int curr = 1;
        
        while (candies > 0) {
            res[i] += min(candies, curr);
            candies -= curr;
            ++curr;
            i = (i + 1) % n;
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        
        for (int i = 0; candies > 0; ++i) {
            res[i % n] += min(candies, i + 1);
            candies -= (i + 1);
        }
        
        return res;
    }
};