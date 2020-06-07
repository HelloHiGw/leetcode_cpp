class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return backtrack(price, special, needs);
    }
    
private:
    bool isValidSpecial(vector<int>& s, vector<int>& needs) {
        int i = 0;
        for (; i < needs.size(); ++i) {
            if (s[i] > needs[i]) break;
        }
        return i == needs.size();
    }
    
    int backtrack(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minPay = 0;
        for (int i = 0; i < needs.size(); ++i) {
            minPay += needs[i] * price[i];
        }
        
        for (auto& s : special) {
            if (!isValidSpecial(s, needs)) continue;
            for (int i = 0; i < needs.size(); ++i) {
                needs[i] -= s[i];
            }
            int pay = s.back() + backtrack(price, special, needs);
            minPay = min(minPay, pay);
            for (int i = 0; i < needs.size(); ++i) {
                needs[i] += s[i];
            }
        }
        return minPay;
    }
};