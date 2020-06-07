class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if (k == num.size()) return "0";
        for (int i = 0; i < num.size(); ++i) {
            while (k && !st.empty() && st.top() > num[i]) {
                st.pop();
                --k;
            }
            st.push(num[i]);
        }
        // additional k
        while (k) {
            st.pop();
            --k;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        // trim leading zeros
        while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
        return res;
        
    }
};


// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         string res;
//         if (num.size() == k) return "0";
//         for (int i = 0; i < num.size(); ++i) {
//             while (k && !res.empty() && res.back() > num[i]) {
//                 res.pop_back();
//                 --k;
//             }
//             res += num[i];
//         }
//         while (k) {
//             res.pop_back();
//             --k;
//         }
//         while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
//         return res;
//     }
// };

/*
Just a few of my intuition to make myself more comfortable about why using greedy. In 
fact, any time you see "smallest","as... as possible", you should try greedy first and 
that might be a really nice solution.

By meaning greedy, we mean to start from most significant digit (left most digit). If you 
can replace that digit (k>0) with a smaller number (by removing that digit), you remove 
it. The following digit takes the place and the number becomes smaller. And as you are 
operating from most significant digit, the resulting number is guaranteed to be the 
smallest.

I agree.
When we try to minimize or maximize something, it usually is a Dynamic Programming 
question. Since Greedy Algorithm (To my knowledge) is a "lucky" version of Dynamic 
Programming, we can try greedy first, and if it doesn't work, switch back to DP.

*/