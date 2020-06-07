class TrieNode{
public:
    bool isWord;
    TrieNode *children[26];

    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        fill(children, children + 26, nullptr);
    }
};

class Trie{
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
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
    }

    bool search(string word) {
        if (root == nullptr) return false;  // maybe after clearing, calling search ?
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int j = word[i] - 'a';
            if (curr->children[j] == nullptr) return false;
            curr = curr->children[j];
        }
        return curr->isWord;
    }

    bool startsWith(string prefix) {
        if (root == nullptr) return false;  // maybe aftering clearing, calling startsWith ?
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int j = prefix[i] - 'a';
            if (curr->children[j] == nullptr) return false;
            curr = curr->children[j];
        }
        return true;
    }

private:
    TrieNode *root;

    void clear(TrieNode* root) {
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) clear(root->children[i]);
        }
        delete root;
    }
};



class TrieNode{
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;

    TrieNode(bool isWord = false) {
        this->isWord = isWord;
        children.clear();
    }
};

class Trie{
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            // the priority of  -> . [] are easy to confused, use ()
            if ((curr->children).count(ch) == 0) {
                (curr->children)[ch] = new TrieNode();
            }
            curr = (curr->children)[ch];
        }
        curr->isWord = true;
    }

    bool search(string word) {
        if (root == nullptr) return false;  // maybe after clearing, calling search ?
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if ((curr->children).count(ch) == 0) return false;
            curr = (curr->children)[ch];
        }
        return curr->isWord;
    }

    bool startsWith(string prefix) {
        if (root == nullptr) return false;  // maybe aftering clearing, calling startsWith ?
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char ch = prefix[i];
            if ((curr->children).count(ch) == 0) return false;
            curr = (curr->children)[ch];
        }
        return true;
    }

private:
    TrieNode *root;

    void clear(TrieNode* root) {
        for (auto& it : root->children) {
            clear(it.second);
        }
        // here need root->children.clear() or not ?
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */