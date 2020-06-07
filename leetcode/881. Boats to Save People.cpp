/*
Sort people.
Each boat carries at most 2 people at the same time
For the current heaviest person, we try to let him go with the lightest person.
As all people need to get on the boat.
If the sum of weight is over the limit, we have to let the heaviest go alone.
No one can take the same boat with him.


At the end of for loop, it may happend that i = j.
But it won't change the result so don't worry about it.

Time Complexity:
O(NlogN)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), [&](int a, int b) {
            return a > b;
        });
        
        int n = people.size();
        int i, j;
        for (i = 0, j = n - 1; i <= j; ++i) {
            if (people[i] + people[j] <= limit) --j;
        }
        return i;
    }
};