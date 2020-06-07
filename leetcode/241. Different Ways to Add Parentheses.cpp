// class Solution {
// public:
//     vector<int> diffWaysToCompute(string input) {
//         vector<int> res;
//         for (int i = 0; i < input.size(); ++i) {
//             char ch = input[i];
//             if (ch == '+' || ch == '-' || ch == '*') {
//                 vector<int> left = diffWaysToCompute(input.substr(0, i));
//                 vector<int> right = diffWaysToCompute(input.substr(i + 1));
//                 for (int num1 : left){
//                     for (int num2 : right) {
//                         if (ch == '+') {
//                             res.push_back(num1 + num2);
//                         } else if (ch == '-') {
//                             res.push_back(num1 - num2);
//                         } else if (ch == '*') {
//                             res.push_back(num1 * num2);
//                         }
//                     }
//                 }
//             }
//         }
//         if (res.empty()) res.push_back(stoi(input));
//         return res;
//     }
// };

/*
Memory search (dp)
There are many repeating subquestions in this recursive method, therefore, 
we could use dynamic programming to avoid this situation by saving the 
results for subquestions
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> m;
        return myDiffWaysToCompute(input, m);
    }
    
private:
    vector<int> myDiffWaysToCompute(string input, unordered_map<string, vector<int>>& m) {
        if (m.count(input)) return m[input];
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = myDiffWaysToCompute(input.substr(0, i), m);
                vector<int> right = myDiffWaysToCompute(input.substr(i + 1), m);
                for (int num1 : left){
                    for (int num2 : right) {
                        if (ch == '+') {
                            res.push_back(num1 + num2);
                        } else if (ch == '-') {
                            res.push_back(num1 - num2);
                        } else if (ch == '*') {
                            res.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        m[input] = res;
        return res;
    }
};