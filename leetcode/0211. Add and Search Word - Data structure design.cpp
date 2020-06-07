class TrieNode{
public:
    bool isWord;
    TrieNode *children[26];

    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        fill(children, children + 26, nullptr);
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (curr->children[j] == nullptr) {
                curr->children[j] = new TrieNode();
            }
            curr = curr->children[j];
        }
        curr->isWord = true;   
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) {
        return searchRoot(root, 0, word);
    }
    
private:
    TrieNode *root;
    
    // easy to write in recursion if permitting regular expression
    bool searchRoot(TrieNode *root, int start, const string& word) {
        if (!root) return false;
        if (start == word.size()) return root->isWord;
        char ch = word[start];
        
        if (ch != '.') return searchRoot(root->children[ch - 'a'], start + 1, word);
        for (int i = 0; i < 26; ++i) {
            if (searchRoot(root->children[i], start + 1, word)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */