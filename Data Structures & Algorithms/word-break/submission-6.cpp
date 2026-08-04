class trie {
public:
    unordered_map<char, trie*> child;
    bool eow = false;
};

class Solution {
public:

trie* root = new trie();

    bool search ( string& str, int i, int j) {
        trie* node = root;

        for ( int idx = i ; idx <= j ; idx++ ) {
            if ( node->child.find(str[idx]) == node->child.end() ) return false;

            node = node->child[str[idx]];
        }

        return node->eow;
    }

    int max(int a, int b) {
        if ( a > b ) return a;
        return b;
    }

    bool solve ( string& s, int st, vector<int>& dp) {
        if ( st == s.size() ) return true;

        if ( dp[st] != -1 ) return dp[st];
        trie* node = root;

        for ( int i = st ; i < s.size() ; i++ ) {

            if ( node->child.find(s[i]) == node->child.end() ) break;

            node = node->child[s[i]];
    

            if( node->eow ) {
                if (solve(s, i+1, dp)) return true;
            }

        }
        return dp[st] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //root = new trie();

        for ( string str : wordDict ) {
            trie* node = root;
            for ( char c : str ) {
                if ( node->child.find(c) == node->child.end() ) {
                    node->child[c] = new trie();
                }

                node = node->child[c];
            }
            node->eow = true;
        }     

        int n = s.size();
        vector<int> dp(n+1, -1);
        dp[n] = true;

        int len = 0;
        for ( string str : wordDict)   
        len = max(len, str.size());

        trie* node = root;

        // for (int i = n - 1; i >= 0; --i) {
        //     for (int j = i; j < min(n, i + len); ++j) {
        //         if (search(s, i, j)) {
        //             dp[i] = dp[j + 1];
        //             if (dp[i]) break;
        //         }
        //     }
        // }

        

        return solve(s, 0, dp);

    }
};
