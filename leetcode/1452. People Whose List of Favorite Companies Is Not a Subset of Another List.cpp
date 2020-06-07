// // O(n*n*(L + L))  O(L) not considering res
// class Solution {
// public:
//     vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
//         vector<int> res;
//         int n =  favoriteCompanies.size();
//         for (int i = 0; i < n; ++i) {
//             bool found = false;
            
//             for (int j = 0; j < n; ++j) {
//                 if (j == i) continue;
//                 if (contains(favoriteCompanies[j], favoriteCompanies[i])) {
//                     found = true;
//                     break;
//                 }
//             }
            
//             if (!found) res.push_back(i);
//         }
//         return res;
//     }
    
// private:
//     bool contains(vector<string>& v1, vector<string>& v2) {
//         if (v1.size() < v2.size()) return false;
//         unordered_set<string> st(v1.begin(), v1.end());
//         for (string& s : v2) {
//             if (!st.count(s)) return false;
//         }
//         return true;
//     }
// };


// // first, convert all vector to unordered_set, then compare st, can pass
// // when comparing, convert vector to unordered_set, TLE
// // because for the same vector, you convert it multiple times, it costs much time in compare function (2L)
// // O(n*L + n*n*L)  O(n*L) not considering res
// class Solution {
// public:
//     vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
//         int n =  favoriteCompanies.size();
//         vector<unordered_set<string>> v;
//         for (auto& company : favoriteCompanies) {
//             v.push_back(unordered_set(company.begin(), company.end()));
//         }
        
//         vector<int> res;
//         for (int i = 0; i < n; ++i) {
//             bool found = false;
            
//             for (int j = 0; j < n; ++j) {
//                 if (j == i) continue;
//                 if (contains(v[j], v[i])) {
//                     found = true;
//                     break;
//                 }
//             }
            
//             if (!found) res.push_back(i);
//         }
//         return res;
//     }
    
// private:
//     bool contains(unordered_set<string>& st1, unordered_set<string>& st2) {
//         if (st1.size() < st2.size()) return false;
//         for (const string& s : st2) {
//             if (!st1.count(s)) return false;
//         }
//         return true;
//     }
// };



// O(n*L*logL + n*n*L)  O(1) not considering res
// n <= 100, L <= 500, logL < n, so it is roughly as method2 in time but O(1) in space
// so this may be better than method2
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n =  favoriteCompanies.size();
        for (auto& v : favoriteCompanies) {
            sort(v.begin(), v.end());
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            bool found = false;
            
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (contains(favoriteCompanies[j], favoriteCompanies[i])) {
                    found = true;
                    break;
                }
            }
            
            if (!found) res.push_back(i);
        }
        return res;
    }
    
private:
    // bool contains(vector<string>& v1, vector<string>& v2) {
    //     if (v1.size() < v2.size()) return false;
    //     int i = 0, j = 0;
    //     while (i < v1.size() && j < v2.size()) {
    //         if (v1[i] == v2[j]) ++j;
    //         ++i;
    //     }
    //     return j == v2.size();
    // }

    bool contains(vector<string>& v1, vector<string>& v2) {
        if (v1.size() < v2.size()) return false;  // without this, also works
        return includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    }
};


// bitset
// O(n * L + n * L + n * n) = O(n * n)   O(n)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n =  favoriteCompanies.size();
        int id = 1;
        unordered_map<string, int> stringToId;
        for (auto& fc : favoriteCompanies) {
            for (auto& s : fc) {
                if (stringToId.count(s)) continue;
                stringToId[s] = id++;
            }
        }
        
        vector<bitset<50010>> v;  // at most 100 * 500 different strings
        bitset<50010> bits;
        for (auto& fc : favoriteCompanies) {
            bits.reset();
            for (auto& s : fc) {
                bits.set(stringToId[s]);
            }
            v.push_back(bits);
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j = 0; j < n && !found; ++j) {
                if (i == j || favoriteCompanies[j].size() < favoriteCompanies[i].size()) continue;
                if ((v[j] & v[i]) == v[i]) found = true;
                // if ((v[j] | v[i]) == v[j]) found = true;  // slower than above
            }
            if (!found) res.push_back(i);
        }
        
        return res;
    }
};


