class TrieNode {
    public:
    unordered_map<char, TrieNode*> chld;
    bool eow = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for ( char c : word ) {
            if ( node->chld.find(c) == node->chld.end() ) 
            node->chld[c] = new TrieNode();

            node = node->chld[c];
        }
        node->eow = true;
        return;
    }

    bool dfs(TrieNode* node, string word, int j) {
        int len = word.size();
        for ( int i = j ; i < len ; i++ ) {
            char c = word[i];
            if ( c == '.' ) {
                for ( auto& child : node->chld ) {
                    if ( dfs(child.second, word, i+1) ) return true;
                }
                return false;
            }

            else if ( node->chld.find(c) == node->chld.end() ) return false;

            node = node->chld[c];
        }

        return node->eow;
    }
    
    bool search(string word) {
        

        return dfs(root, word, 0);
    }
};
