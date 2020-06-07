class TrieNode{
public:
    bool isWord;
    string word;
    TrieNode *children[26];
    
    TrieNode(bool isWord = false, string word = "") {
        this->isWord = isWord;
        this->word = word;
        fill(children, children + 26, nullptr);
    }
};

class Trie{
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (curr->children[j] == nullptr) {
                curr->children[j] = new TrieNode();
            }
            curr = curr->children[j];
        }
        curr->isWord = true;
        curr->word = word;
    }
    
};

// class Solution {
// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         Trie *t = new Trie();
//         for (const string& word : words) {
//             t->insert(word);
//         }
        
//         vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//         // use unordered_set to remove duplicates
//         // consider [['a', 'b'], ['c', 'd']]  ["a"]
//         // when comes to b or c, it insert twice
//         unordered_set<string> st;
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
//                 dfs(t->root, i, j, board, dirs, visited, st);
//             }
//         }
        
//         vector<string> res;
//         for (const string& s : st) {
//             res.push_back(s);
//         }
//         return res;
//     }
    
// private:
    
//     void dfs(TrieNode *root, int i, int j, vector<vector<char>>& board, vector<vector<int>>& dirs, vector<vector<int>>& visited, unordered_set<string>& st) {
//         if (!root) return;
//         // this must be before boundary judgement
//         // consider [['a']] ["a"]
//         if (root->isWord) {
//             st.insert(root->word);
//         }
        
//         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
//         if (visited[i][j]) return;
//         visited[i][j] = true;
        
//         TrieNode *child = root->children[board[i][j] - 'a'];
//         for (const auto& d : dirs) {
//             dfs(child, i + d[0], j + d[1], board, dirs, visited, st);
//         }
        
//         // must recover visited[i][j]
//         // consider [['a', 'b'], ['c', 'd']] ["acdb"]
//         // cannot reach from 'b', but can reach from 'c'
//         visited[i][j] = false;
//     }
// };


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *t = new Trie();
        for (const string& word : words) {
            t->insert(word);
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(t->root, i, j, board, dirs, res);
            }
        }
        return res;
    }
    
private:
    
    void dfs(TrieNode *root, int i, int j, vector<vector<char>>& board, vector<vector<int>>& dirs, vector<string>& res) {
        if (!root) return;
        // this must be before boundary judgement
        // consider [['a']] ["a"]
        if (root->isWord) {
            res.push_back(root->word);
            // avoid duplicates by setting root->isWord = false;
            root->isWord = false;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return;
        
        char ch = board[i][j];
        // set '#' as visited
        board[i][j] = '#';
        TrieNode *child = root->children[ch - 'a'];
        for (const auto& d : dirs) {
            dfs(child, i + d[0], j + d[1], board, dirs, res);
        }
        board[i][j] = ch;
    }
};




