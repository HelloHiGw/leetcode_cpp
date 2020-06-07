class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(40);
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int t = i, sum = 0;
            while (t) {
                sum += t % 10;
                t /= 10;
            }
            mx = max(mx, ++count[sum]);
        }
        
//         int res = 0;
//         for (int i = 1; i < 40; ++i) {
//             if (count[i] == mx) ++res;
//         }
//         return res;
        return count_if(count.begin(), count.end(), [&mx](int n){
            return n == mx;
        });
    }
};