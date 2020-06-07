/*
cannot use xor, case [2, 2, 2, 2]

O(nlogn)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // binary search the answer [1, n]
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }
            
            if (cnt > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/*
https://leetcode.com/problems/linked-list-cycle-ii/. 

Step 1:
The array's indices are in [0, n]. The array's values are in [1, n]. This means nums[0] will 
lead us to an index that is in [1, n] (because nums[0] is a value). But nobody will lead us back 
to index 0 (because everyone's value is in [1, n] not including 0).

Step 2:
Starting from index 0, we can definitely reach a cycle. Why? By contradiction. If we cannot 
reach a cycle, that is to say, we always meet a new index, and then meet a new index, 
but there are only finite number of indices. So we will reach a cycle.

Step 3:
Then this cycle's entrace's index must be one duplicated number (because two guys lead us to it).

Step 4:
Since there is only one duplicated number, then that's it.



Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3

What is the distance fast moved? 2. What is the distance slow moved? 3. And their relationship?
x1 + x2 + x3 + x2
x1 + x2
x1 + x2 + x3 + x2 = 2 (x1 + x2)
Thus x1 = x3, that's the reason we reset slow to be 0.

Finally got the idea.

1 3 4 2 2
0 1 2 3 4

1 -> 3 -> 2 -> 4
          |    |
          ------
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*
O(n) modify the array
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) return abs(nums[i]);
            nums[index] = -nums[index];
        }
        return -1;
    }
};