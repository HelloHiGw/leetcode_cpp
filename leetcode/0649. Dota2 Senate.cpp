// // TLE written by myself
// class Solution {
// public:
//     string predictPartyVictory(string senate) {
//         int cntR = 0, cntD = 0;
//         vector<int> isBanned(senate.size(), false);
//         for (char ch : senate) {
//             ch == 'R' ? ++cntR : ++cntD;
//         }
//         int n = senate.size();
//         while (cntR && cntD) {
//             for (int i = 0; i < n; ++i) {
//                 if (isBanned[i]) continue;
//                 for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {  // frist ban opponent after i, then opponent before i
//                     if (senate[j] != senate[i] && !isBanned[j]) {
//                         isBanned[j] = true;
//                         senate[j] == 'R' ? --cntR : --cntD;
//                         break;
//                     }
//                 }
//             }
//         }
//         return cntR ? "Radiant" : "Dire";
//     }
// };


// use queue to reduce complexity of banning from O(n) to O(1)
// so time complexity is O(n)
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> queR, queD;
        for (int i = 0; i < senate.size(); ++i) {
            senate[i] == 'R' ? queR.push(i) : queD.push(i);
        }
        int n = senate.size();
        while (!queR.empty() && !queD.empty()) {
            int indexR = queR.front();queR.pop();
            int indexD = queD.front();queD.pop();
            indexR < indexD ? queR.push(indexR + n) : queD.push(indexD + n);
        }
        return queR.empty() ? "Dire" : "Radiant";
    }
};

