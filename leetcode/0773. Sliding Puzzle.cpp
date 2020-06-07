/*
change board to string 
0 1 2 
3 4 5 

to 0 1 2 3 4 5

There are at most 6! permutation of the 6 numbers: 0~5. 
For each permustion, cost spaceO(6); 
String.indexOf() and String.equals() cost time O(6). 
Therefore, space and time both cost 6 * 6! = 4320.
*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> neighbors = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        
        string curr, target = "123450";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                curr += board[i][j] + '0';
            }
        }
        
        queue<string> que;
        unordered_set<string> visited;
        que.push(curr);
        visited.insert(curr);
        
        for (int steps = 0; !que.empty(); ++steps) {
            for (int i = que.size(); i > 0; --i) {
                curr = que.front();que.pop();
                if (curr == target) return steps;

                int pos = curr.find('0');
                for (int nei : neighbors[pos]) {
                    string next = curr;
                    swap(next[pos], next[nei]);
                    if (!visited.count(next)) {
                        que.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};

