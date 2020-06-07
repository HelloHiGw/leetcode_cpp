// // O(n * log26)  O(26)
// class Solution {
// public:
//     string reorganizeString(string S) {
//         unordered_map<char, int> count;
//         for (char ch : S) ++count[ch];
//         priority_queue<pair<int, char>> pq;
//         for (auto& it : count) {
//             if (it.second > (S.size() + 1) / 2) return "";
//             pq.push({it.second, it.first});
//         }
         
//         string res;
//         while (pq.size() > 1) {  // Greedy: fetch char of max count as next char in the result.
//             auto temp1 = pq.top();pq.pop();
//             auto temp2 = pq.top();pq.pop();
//             // c1 c2, next level the first char must not be c2
//             // because c1 is in front of c2 this level
//             // both --count, next level c1 is also in front of c2 (if in queue)
//             res += temp1.second;
//             res += temp2.second;
//             if (--temp1.first > 0) pq.push(temp1);
//             if (--temp2.first > 0) pq.push(temp2);
//         }
//         if (!pq.empty()) res += pq.top().second;
//         return res; 
//     }
// };


// O(n)  O(26)
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> count;
        char maxChar;
        int maxCount = 0;
        for (char ch : S) {
            if (++count[ch] > maxCount) {
                maxChar = ch;
                maxCount = count[ch];
            }
        }
        if (maxCount > (S.size() + 1) / 2) return "";
        
        int index = 0;
        string res = S;  // exactly, res is size of S.size() with empty chars
        while (count[maxChar]) {  // aab, you must fill maxChar first, otherwise b  a wrong
            res[index] = maxChar;
            --count[maxChar];
            index += 2;
        }
        
        int index = 0;
        string res = S;
        for (auto& it : count) {
            while (it.second) {
                if (index >= res.size()) index = 1;
                res[index] = it.first;
                --it.second;
                index += 2;
            }
        }
        
        return res;
    }
};

/*
We construct the resulting string in sequence: at position 0, 2, 4, ... and then 1, 3, 5, ...
In this way, we can make sure there is always a gap between the same characters

Consider this example: "aaabbbcdd", we will construct the string in this way:

a _ a _ a _ _ _ _ // fill in "a" at position 0, 2, 4
a b a _ a _ b _ b // fill in "b" at position 6, 8, 1
a b a c a _ b _ b // fill in "c" at position 3
a b a c a d b d b // fill in "d" at position 5, 7
*/