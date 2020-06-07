class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> sorted = arr;
        nth_element(sorted.begin(), sorted.begin() + (n - 1) / 2, sorted.end());
        int median = sorted[(n - 1) / 2];
        
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int d1 = abs(a - median), d2 = abs(b - median);
            if (d1 != d2) return d1 > d2;
            return a > b;
        });
        return vector<int>(sorted.begin(), sorted.begin() + k);
    }
};


class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int median = arr[(n - 1) / 2];
        
        vector<int> res;
        for (int i = 0, j = n - 1; res.size() < k;) {
            if (abs(arr[j] - median) >= abs(arr[i] - median)) {
                res.push_back(arr[j--]);
            } else {
                res.push_back(arr[i++]);
            }
        }
        return res;
    }
};