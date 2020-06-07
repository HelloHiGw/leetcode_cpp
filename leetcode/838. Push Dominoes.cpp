/*
Here is another idea that focus on 'L' and 'R'.
'R......R' => 'RRRRRRRR'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
'L......R' => 'L......R'
'L......L' => 'LLLLLLLL'

two pointers
O(n)
*/
class Solution {
public:
    string pushDominoes(string d) {
        // add front 'L' and back 'R' to conveniently tackle with
        // front ... and back ...
        d = 'L' + d + 'R';
        string res;
        
        for (int left = 0, right = 1; right < d.size(); ++right) {
            if (d[right] == '.') continue;
            // count between left and right
            int count = right - left - 1;
            // do not forget the left char
            // the additional front 'L' will not be a char of answer
            if (left) res += d[left];
            
            if (d[left] == d[right]) {
                res += string(count, d[left]);
            } else if (d[left] == 'L' && d[right] == 'R') {
                res += string(count, '.');
            } else {
                res += string(count / 2, 'R') + string(count % 2, '.') + string(count / 2, 'L');
            }
            
            left = right;
        }
        
        return res;
    }
};