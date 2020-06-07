// // TLE
// class Solution {
// public:
//     int countNumbersWithUniqueDigits(int n) {
//         int size = pow(10, n);
//         vector<bool> dp(size);  // no constexpr is feasible ? 
//         int res = 0;
//         for (int i = 0; i < size; ++i) {
//             if (i < 10) {
//                 dp[i] = true;
//                 ++res;
//             } else {
//                 int d1 = i / 10, d2 = i % 10;
//                 if (dp[d1] && isUnique(d1, d2)) {
//                     ++res;
//                     dp[i] = true;
//                 } 
//             }
//         }
//         return res;
//     }
    
// private:
//     bool isUnique(int d1, int d2) {
//         while (d1) {
//             if (d2 == d1 % 10) return false;
//             d1 /= 10;
//         }
//         return true;
//     }
// };



class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10;
        int availableNumbers = 9;
        int uniqueNumbers = 9;
        while (n > 1 && availableNumbers) { // rule starts from n == 2, f(2) = 9 * 9, f(3) = f(2) * 8
            uniqueNumbers = uniqueNumbers * availableNumbers;
            res += uniqueNumbers;
            --n;
            --availableNumbers;
        }
        return res;
    }
};
/*
Following the hint. Let f(n) = count of number with unique digits of length n.

f(1) = 10. (0, 1, 2, 3, ...., 9)

f(2) = 9 * 9. Because for each number i from 1, ..., 9, we can pick j to form a 2-digit number ij and there are 9 numbers that are different from i for j to choose from.

f(3) = f(2) * 8 = 9 * 9 * 8. Because for each number with unique digits of length 2, say ij, we can pick k to form a 3 digit number ijk and there are 8 numbers that are different from i and j for k to choose from.

Similarly f(4) = f(3) * 7 = 9 * 9 * 8 * 7....

...

f(10) = 9 * 9 * 8 * 7 * 6 * ... * 1

f(11) = 0 = f(12) = f(13)....
*/