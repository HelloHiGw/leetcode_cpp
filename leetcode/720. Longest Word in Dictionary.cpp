/*
time O(n * L)
space O(n * L)
*/

class TrieNode{
public:
    bool isWord;
    string word;
    TrieNode *children[26];

    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        this->word = "";
        fill(children, children + 26, nullptr);
    }
};


class Trie{
public:
    Trie() {
        // root->isWord = true, otherwise dfs will return false at the beginning
        // root->word = "", do not affect the answer
        root = new TrieNode(true);  
    }

    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (curr->children[j] == nullptr) {
                curr->children[j] = new TrieNode();
            }
            curr = curr->children[j];
        }
        curr->isWord = true;
        // store the word, so when dfs, you need not to keep the path
        // curr + (char)(i + 'a') is pretty wasting time
        curr->word = word;  
    }
    
    string findLongestWord() {
        string res;
        // dfs(root, res);
        bfs(root, res);
        return res;
    }
    
private:
    TrieNode *root;
    
    void dfs(TrieNode* root, string& res) {
        // root = nullptr or root is not a word
        // then the following cannot be built one characrer at a time
        if (!root || !root->isWord) return;
        string curr = root->word;
        
        // curr.size() is just the depth of curr level
        if (curr.size() > res.size() || curr.size() == res.size() && curr < res) {
            res = curr;
        }
        
        for (int i = 0; i < 26; ++i) {
            dfs(root->children[i], res);
        }
    }
    
    void bfs(TrieNode* root, string& res) {
        queue<TrieNode*> que;
        que.push(root);
        while (!que.empty()) {
            // we only want the depthest level, if !que.empty(), there is deepest level
            for (int i = que.size(); i > 0; --i) {
                root = que.front();que.pop();
                // we firstly push higher char(25), so the last is answer
                res = root->word;
                for (int i = 25; i >= 0; --i) {
                    TrieNode *child = root->children[i];
                    if (child && child->isWord) {
                        que.push(child);
                    }
                }
            }
        }
    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *t = new Trie();
        for (string& word : words) {
            t->insert(word);
        }
        return t->findLongestWord();
    }
};


/*
time O(n * logn * L)
space O(n * L)
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string& word : words) {
            if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
                // sort by lexicographical order, same length, the first is the answer
                // apple is before apply
                if (word.size() > res.size()) res = word;
                built.insert(word);
            }
        }
        return res;
    }
};
