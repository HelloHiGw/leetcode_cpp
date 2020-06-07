// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int num : nums) {
//             pq.push(num);
//             if (pq.size() > k) pq.pop();
//         }
//         return pq.top();
//     }
// };

/*
T(n) = T(n / 2) + O(n) = T(n / 4) + O(n / 2) + O(n) = ... = T(n / 2^x) + (1 / 2^x-1 + .. + 1 / 4 + 1 / 2 + 1) * O(n) 
     = T(n / 2^x) + O(n) = O(n) ?    
T(n) = T(n - 1) + O(n)  = O(n^2)
without random partition, average : O(n) O(logn)  worst : O(n^2) O(n)

with random partition, is O(n) O(logn), worst case rarely happens
*/
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         return findKthSmallest(nums, 0, nums.size() - 1, nums.size() - k + 1);
//     }
    
// private:
//     int findKthSmallest(vector<int>& nums, int start, int end, int k) {
//         int pos = partition(nums, start, end);
//         int order = pos - start + 1;  // attention here
//         if (order == k) {
//             return nums[pos];
//         } else if (order > k) {
//             return findKthSmallest(nums, start, pos - 1, k);
//         } else {
//             return findKthSmallest(nums, pos + 1, end, k - order);
//         }
//     }
    
//     int partition(vector<int>& nums, int start, int end) {
//         int p = round(1.0 * rand() / RAND_MAX * (end - start)) + start;
//         swap(nums[p], nums[start]);
//         int temp = nums[start];
//         while (start < end) {
//             while (start < end && nums[end] > temp) --end;
//             nums[start] = nums[end];
//             while (start < end && nums[start] <= temp) ++start;
//             nums[end] = nums[start];
//         }
//         nums[start] = temp;
//         return start;
//     }
// };


// time is the same as above O(n) (worst O(n^2) rarely happens)
// space is O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // change to the kth element from left to right is more readable
        return findKthSmallest(nums, nums.size() - k + 1);
    }
    
private:
    int findKthSmallest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        while (true) {  // while(start <= end) also works, but not while(start < end), if so, get wrong answer when recursive to only one element
            int pos = partition(nums, start, end);
            if (pos + 1 == k) {
                return nums[pos];
            } else if (pos + 1 < k) {  // no recursive like above
                start = pos + 1;
            } else {
                end = pos - 1; 
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int start, int end) {
        // random partition get O(n) beats 99%, or worst is O(n^2)
        int p = round(1.0 * rand() / RAND_MAX * (end - start)) + start;
        swap(nums[p], nums[start]);
        int temp = nums[start];
        while (start < end) {
            while (start < end && nums[end] > temp) --end;
            nums[start] = nums[end];
            while (start < end && nums[start] <= temp) ++start;
            nums[end] = nums[start];
        }
        nums[start] = temp;
        return start;
    }
};