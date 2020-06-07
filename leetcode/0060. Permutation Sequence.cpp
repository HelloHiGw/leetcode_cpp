// // TLE
// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         string curr = "";
//         vector<string> res;
//         vector<bool> visited(n + 1, false);
//         backtrack(n, k, visited, curr, res);
//         return res.back();
//     }
    
//     void backtrack(int n, int k, vector<bool>& visited, string& curr, vector<string>& res) {
//         if (curr.size() == n) {
//             res.push_back(curr);
//             return;
//         }
//         if (res.size() == k) return;
//         // dfs, so the order is 123 132 213 231... like the description
//         for (int i = 1; i <= n; ++i) {
//             if (visited[i]) continue;
//             curr += to_string(i);
//             visited[i] = true;
//             backtrack(n, k, visited, curr, res);
//             curr.pop_back();
//             visited[i] = false;
//         }
//     }
    
// };


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
            num.push_back(i);
        }
        --k;  // index from 0, if k = 6, 6 / 2! = 3, the first num is num[2] = 3 not num[3] = 4
        string res;
        for (int i = 0; i < n; ++i) {
            fact /= n - i;
            int index = k / fact;
            res += to_string(num[index]);
            num.erase(num.begin() + index);  // need remove, when first 2 is settled, afterwards we only need 1 and 3, index = 1 shoud be 3
            k -= index * fact;
        }
        return res;
    } 
};

/*
say n = 4, you have {1, 2, 3, 4}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)


We know how to calculate the number of permutations of n numbers... n! So each of those with permutations of 3 numbers means there are 6 possible permutations. Meaning there would be a total of 24 permutations in this particular one. So if you were to look for the (k = 14) 14th permutation, it would be in the

3 + (permutations of 1, 2, 4) subset.

To programmatically get that, you take k = 13 (subtract 1 because of things always starting at 0) and divide that by the 6 we got from the factorial, which would give you the index of the number you want. In the array {1, 2, 3, 4}, k/(n-1)! = 13/(4-1)! = 13/3! = 13/6 = 2. The array {1, 2, 3, 4} has a value of 3 at index 2. So the first number is a 3.
*/