class PrefixTree {
private: 
class TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
    friend class PrefixTree;
};

public:

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur =  cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        auto* cur = root;
        for(char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto* cur = root;
        for(char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
private:
    TrieNode* root;
};
