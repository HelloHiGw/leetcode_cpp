/*
Sort tokens.
Buy at the cheapest and sell at the most expensive.
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n - 1;
        int points = 0;
        int res = 0;
        
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {  // only when P is not sufficent, we exchange points for P
                --points;
                P += tokens[j--];
            } else {
                break;
            }
        }
        
        return res;
    }
};