// class Solution {
// public:
//     vector<int> grayCode(int n) {
//         bitset<32> bits;
//         vector<int> res;
//         backtrack(n, bits, res);
//         return res;
//     }
    
//     void backtrack(int n, bitset<32>& bits, vector<int>& res) {
//         if (n == 0) {
//             res.push_back(bits.to_ulong());
//             return;
//         }
//         backtrack(n - 1, bits, res);
//         bits.flip(n - 1);
//         backtrack(n - 1, bits, res);
//     }
// };

/*
000
001
011
010
110
111
101
100

Excellent recursion! This is quite a brilliant solution. However, I don't think 
this is a typical backtracking problem and this solution is not a typical 
backtracking method. In my opinion, what a typical backtracking method does is 
"choose-explore-unchoose". This solution first put the current bits to the result 
vector, then flip the (k-1)th position, and put the flipped bits to the result 
vector. Hence, what this solution dose is inserting both unflipped and flipped bits 
to the result vector.
*/





class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0};
        for (int i = 0; i < n; ++i) {
            // j = res.size() - 1, because we want the mirror from end to begin
            // we push_back res[j] plus a leading 1
            // the original is treated res[j] plus a leading 0
            for (int j = res.size() - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};

/* 
https://www.cnblogs.com/grandyang/p/4315649.html
res:
00 --> 000
01 --> 001
11 --> 011
10 --> 010

mirror
10 --> 110
11 --> 111
01 --> 101
00 --> 100

I think this may explain the author's idea much clearly on the statement "The 
middle two numbers only differ at their highest bit, while the rest numbers of part 
two are exactly symmetric of part one".
Say the example input is 3.

0 000
1 001
3 011
2 010

6 110
7 111
5 101
4 100

For the pair of (2, 6), (3, 7), (1, 5) and (0, 4), the last 2 bits are the same. 
The only difference is 6,7,5 and 4 set the first bit on. Hope this helps.

*/