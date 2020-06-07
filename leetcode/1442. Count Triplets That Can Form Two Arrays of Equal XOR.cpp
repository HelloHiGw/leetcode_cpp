// TLE 43 / 47 test cases passed.  O(n^4)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                for (int k = j; k < arr.size(); ++k) {
                    int a = 0, b = 0;
                    for (int t = i; t < j; ++t) a ^= arr[t];
                    for (int t = j; t <= k; ++t) b ^= arr[t];
                    if (a == b) ++res;
                }
            }
        }
        return res;
    }
};


// O(n^3)
// x[i] ^ x[i + 1] ^ ... ^ x[j - 1] equals m ^ n
// m = x[0] ^ x[1] ^ ... ^ x[i - 1] 
// n = x[0] ^ x[1] ^ ... ^ x[i - 1] ^ x[i] ^ ... ^ x[j - 1]
// = x[i] ^ x[j]
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> xors(arr.size() + 1);  // xors[i] = arr[0]^...arr[i - 1]
        for (int i = 0; i < arr.size(); ++i) xors[i + 1] = xors[i] ^ arr[i];
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                for (int k = j; k < arr.size(); ++k) {
                    int a = xors[i] ^ xors[j];
                    int b = xors[j] ^ xors[k + 1];
                    if (a == b) ++res;
                }
            }
        }
        return res;
    }
};


// O(n^2)
// a == b denotes x[j] ^ ... ^ x[k] = 0
// denotes x[0] ^ ... ^ x[j - 1] = x[0] ^ ... x[k]
// i.e. xors[j] = xors[k + 1]
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> xors(arr.size() + 1);  // xors[i] = arr[0]^...arr[i - 1]
        for (int i = 0; i < arr.size(); ++i) xors[i + 1] = xors[i] ^ arr[i];
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int k = i + 1; k < arr.size(); ++k) {
                // if ((xors[i] ^ xors[k + 1]) == 0) res += k - i;
                if (xors[i] == xors[k + 1]) res += k - i;  // k - i positions of j
            }
        }
        return res;
    }
};

// O(n)
// we want find xors[i1] == xors[i2] == xors[i3] == xors[i4]... then
// res += i2 - i1 + 1
// + i3 - i1 - 1 + i3 - i2 - 1 = 2 * i3 - (i1 + 1 + i2 + 1)
// + i4 - i1 - 1 + i4 - i2 - 1 + i4 - i3 - 1 = 3 * i4 - (i1 + 1 + i2 + 1 + i3 + 1)
// i.e. res += freq[X] * i - sum[X]
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> xors(arr.size() + 1);  
        unordered_map<int, int> freq{{0, 1}};  // crucial such as [1, 1]
        unordered_map<int, int> sum;
        int res = 0, X = 0;
        for (int i = 0; i < arr.size(); ++i) {
            X ^= arr[i];
            res += freq[X] * i - sum[X];
            ++freq[X];
            sum[X] += i + 1;
        }
        return res;
    }
};