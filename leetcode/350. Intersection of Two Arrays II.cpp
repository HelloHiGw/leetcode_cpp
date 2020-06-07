// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> m;
//         for (int num : nums1) ++m[num];
//         vector<int> res;
//         for (int num : nums2) {
//             if (m.count(num) && m[num] > 0) {
//                 res.push_back(num);
//                 --m[num];
//             }
//         }
//         return res;
//     }
// };


// following up 1, if two arrays are sorted
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }
};


/*
If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, 
read chunks of array that fit into the memory, and record the intersections. 
(covert to Solution1)


If both nums1 and nums2 are so huge that neither fit into the memory,
read (let's say) 2G of each into memory and then using the 2 pointer technique, 
then read 2G more from the array that has been exhausted. 
Repeat this until no more data to read from disk.

if you read 2 elements (each array 1) at a time, this procedure will take forever. 
In principle, we want minimize the number of disk access during the run-time.
*/

