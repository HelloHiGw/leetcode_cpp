// class Solution {
// public:
//     string decodeString(string s) {
//         if (s.find('[') == string::npos) return s;
//         string res;
//         for (int i = 0; i < s.size(); ++i) {
//             if (isdigit(s[i])) {
//                 int bracketStart = s.find('[', i);
//                 int k = stoi(s.substr(i, bracketStart - i));
//                 int cnt = 0, j = 0;  // j bracketEnd
//                 for (j = start; j < s.size(); ++j) {
//                     if (s[j] == '[') {
//                         ++cnt;
//                     } else if (s[j] == ']') {
//                         --cnt;
//                         if (cnt == 0) break;
//                     }
//                 }
//                 int repeatLength = (j - 1) - (bracketStart + 1) + 1;
//                 string repeat = decodeString(s.substr(bracketStart, repeatLength));
//                 for (int m = 0; m < k; ++m) res += repeat;
//                 i = j;
//             } else {
//                 res += s[i];
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    string decodeString(string s) {
        stack<int> intStack;
        stack<string> strStack;
        int k = 0;
        string str;  
        // when it comes to 2[bc], str = aaa, we push 2 and aaa into stack
        // then str becomes bc, then concatenate, str = strStack.top()(aaa) + bc + bc
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                k = k * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                intStack.push(k);
                strStack.push(str);
                k = 0;
                str = "";
            } else if (s[i] == ']') {
                string preStr = strStack.top();
                strStack.pop();
                int cnt = intStack.top();
                intStack.pop();
                for (; cnt > 0; --cnt) preStr += str;
                str = preStr;
            } else {
                str += s[i];
            }
        }
        return str;
    }
};