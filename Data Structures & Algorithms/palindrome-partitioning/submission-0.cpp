class Solution {
public:

    bool is_palin ( string s, int st, int end ) {
        int k = 0;
        for ( int i = st ; i <= end ; i++ ) {
            if ( s[i] != s[end - k] ) return false;

            k++;
        }

        return true;
    }

    void helper ( int st, int n, string s, vector<string>& ans, vector<vector<string>>& res) {
        if ( st > n ) return;

        if ( st == n ) {
            res.push_back(ans);
            return;
        }

        for ( int i = st ; i < n ; i++ ) {
            if ( is_palin(s, st, i) ) {
                ans.push_back(s.substr(st, i-st+1));
                helper(i+1, n, s, ans, res);

                ans.pop_back();
            }
        }

        return;
        
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> ans;
        vector<vector<string>> res;
       // string lol;

        helper(0, n, s, ans, res);

        return res;
    }
};
