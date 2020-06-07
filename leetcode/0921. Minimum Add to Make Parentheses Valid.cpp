/*
left records the number of ( we need to add on the left of S.
right records the number of ) we need to add on the right of S


Loop char c in the string S:
if (c == '('), we increment right,
if (c == ')'), we decrement right.
When right is already 0, we increment left
Return left + right in the end
*/
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        int n = S.size();
        
        for (int i = 0; i < n; ++i) {
            if (S[i] == '(') {
                ++right;
            } else if (right > 0) {
                --right;
            } else {
                ++left;
            }
        }
        return left + right;
    }
};