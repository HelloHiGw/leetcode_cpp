class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> res = {1};
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int minVal = min(min(m2, m3), m5);
            if (minVal == m2) ++i2;
            if (minVal == m3) ++i3;
            if (minVal == m5) ++i5;
            res.push_back(minVal);
        }
        return res.back();
    }
};

/*
Let's say we have the first 3 ugly numbers 1, 2, 3. What would be the next number? 
the next number has to be the the smallest number among 2*(1,2,3), 3*(1,2,3), 5*(1,2,3). 
Obviously, the smallest number is 2 * 1 = 2. But wait, 2 is already in there. 
So precisely speaking, the next number has to be the the smallest number among 
all the existing numbers multiplied by 2, 3,5 that isn't in the list already. 
Good news is that we can solve this in a DP-like approach. First, 
we assume there is only one number in the list, which is 1. 
The next number is Min(2 * 1, 3 * 1, 5 * 1)=2 and it is not in the list. 
Because we have already considered 2*1 (we move the pointer to its next position, which is 2), 
now we only need to consider 2 * 2, 3 * 1, 5 * 1 in the next iteration. 
This way, we don't have to worry about finding a number that is already in the list.

simulate you will know
*/