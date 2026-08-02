class TrieNode {
public : 
    unordered_map<char, TrieNode*> chld;
    bool eow = false;
};


class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for ( char c : word ) {
            if ( curr->chld.find(c) == curr->chld.end()) {
                curr->chld[c] = new TrieNode();
            }
            curr = curr->chld[c];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for ( char c : word ) {
            if ( node->chld.find(c) == node->chld.end() ) return false;

            else {
                node = node->chld[c];
            }  
        }
        if( node->eow == true ) return true;

        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for ( char c : prefix ) {
            if ( node->chld.find(c) == node->chld.end()) return false;

            node = node->chld[c];
        }
        return true;
    }
};
