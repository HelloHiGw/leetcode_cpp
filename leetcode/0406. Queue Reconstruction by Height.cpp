// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         sort(people.begin(), people.end(), cmp);
//         vector<vector<int>> res;
//         for (auto& p : people) {
//             res.insert(res.begin() + p[1], p);
//         }
//         return res;
//     }
    
// private:
//     static bool cmp(vector<int> v1, vector<int> v2) {
//         if (v1[0] != v2[0]) return v1[0] > v2[0];
//         return v1[1] < v2[1];
//     }
// };

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[0] != v2[0]) return v1[0] > v2[0];
            return v1[1] < v2[1];
        });
        vector<vector<int>> res;
        for (auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};

/*
Pick out tallest group of people and sort them in a subarray (S). 
Since there's no other groups of people taller than them, 
therefore each guy's index will be just as same as his k value.

For 2nd tallest group (and the rest), insert each one of them into (S) by k value. 
So on and so forth.
*/